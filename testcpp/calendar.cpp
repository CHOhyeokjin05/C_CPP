#include <iostream>
class Date{
    int year_;
    int month_;
    int day_;

    int d_arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ld_arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public:
        Date(int year, int month, int day){
            year_ = year;
            month_ = month;
            day_ = day;
        };
        void SetDate(int year, int month, int day){
            year_ = year;
            month_ = month;
            day_ = day;
        }
        void AddYear(int inc){
            year_ += inc;
        }
        void AddMonth(int inc){
            month_ += inc;
            while(month_ > 12){
                month_ -= 12;
                this->AddYear(1);
            }
        }
        void AddDay(int inc){
            day_ = day_ + inc;
            if(year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0){
                while(day_ > ld_arr[month_ - 1]){
                    day_ -= ld_arr[month_ - 1];
                    this->AddMonth(1);
                }
            }
            else{
                while(day_ > d_arr[month_ - 1]){
                    day_ -= d_arr[month_ - 1];
                    this->AddMonth(1);
                }
            }
        }
        void ShowDate(){
            std::cout << year_ << std::endl;
            std::cout << month_ << std::endl;
            std::cout << day_ << std::endl;
        }
};

int main(){
    Date calendar(2000, 11, 30);
    calendar.SetDate(2000, 12, 30);
    calendar.AddDay(1);
    calendar.AddMonth(1);
    calendar.ShowDate();
}