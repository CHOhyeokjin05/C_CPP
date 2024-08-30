#include <iostream>
#include <math.h>

class Point{

    public:
        int x, y;
        Point(int pos_x, int pos_y){
            x = pos_x;
            y = pos_y;
        }
        void print(){
            std::cout << "(" << x << ", " << y << ") ";
        }
};

class Geometry{
    Point* point[100];

    private:
        Point* point_array[100];
        int num_points;

    public:
        Geometry(){
            num_points = 0;
        }
        void AddPoint(const Point &point){
            point_array[num_points++] = new Point(point.x, point.y);
        }
        // 모든 점들 간의 거리를 출력하는 함수 입니다.
        void PrintDistance();

        // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
        // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
        // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
        // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void PrintNumMeets();
};

void Geometry::PrintDistance(){
    int dx, dy;
    double distance;
    for(int i=0; i<num_points-1; i++){
        for(int j=i+1; j<num_points; j++){
            dx = point_array[i]->x - point_array[j]->x;
            dy = point_array[i]->y - point_array[j]->y;
            distance = std::sqrt(dx*dx + dy* dy);
            point_array[i]->print();
            point_array[j]->print();
            std::cout << "->" << distance << std::endl;
        }
    }
}

void Geometry::PrintNumMeets(){
    int a, b, c;
    int x1, y1, x2, y2;
    int num = 1;
    a = point_array[1]->y - point_array[0]->y;
    b = point_array[0]->x - point_array[1]->x;
    c = point_array[1]->x * point_array[0]->y - point_array[0]->x * point_array[1]->y;
    for(int i=0; i<num_points-1; i++){
        for(int j=i+1; j<num_points; j++){
            x1 = point_array[i]->x;
            y1 = point_array[i]->y;
            x2 = point_array[j]->x;
            y2 = point_array[j]->y;
            if((a*x1+b*y1+c) * (a*x2+b*y2+c) < 0){
                num++;
            }
            else if(-b*(x2-x1) == a*(y2-y1)){
                continue;
            }
            else{
                num++;
            }
        }
    }
    std::cout << num << std::endl;

}


int main(){
    Geometry g = Geometry();
    g.AddPoint(Point(0, 1));
    g.AddPoint(Point(3, 4));
    g.AddPoint(Point(-1, -10));
    g.AddPoint(Point(2,-7));
    g.PrintDistance();
    g.PrintNumMeets();
}