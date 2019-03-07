#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//��ȡĳ�µ�����
	int Getmonthday(int _year, int _month)
	{
		//����
		if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
		{
			if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
			{
				return 31;
			}
			else if (_month==2)
			{
				return 29;
			}
			else
			{
				return 30;
			}
		}
		else //ƽ��
		{
			if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
			{
				return 31;
			}
			else if(_month==2)
			{
				return 28;
			}
			else
			{
				return 30;
			}
		}
	}
	//�ж������Ƿ�Ϸ�
	bool IsInvalid(int year, int month, int day)//�ж������Ƿ�Ϸ�
	{
		//�˴���1900�꿪ʼ�����С��������ڣ��򷵻�fasle
		return ((year > 1900) && (month > 0) && (month<13) && (day>0) && (day < Getmonthday(year, month)));
    }

	//ǰ��++
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//����++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int days)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	//days��֮�������
	Date operator+(int days)
	{
		_day += days;
		return *this;
	}
	//days��֮ǰ������
	Date operator-(int days)
	{
		_day -= days;
		return *this;
	}
	//������֮��ľ���
	int operator-(const Date& d)
	{
		Date maxDate = *this;
		Date minDate = d;
		if (maxDate<minDate)
		{
			maxDate = d;
			minDate = *this;
		}
		int days = 0;
		while (minDate!=maxDate)
		{
			++minDate;
			days++;
		}
		return days;
	}
	bool operator==(const Date&d)
	{
		return (_year = d._year) &&
			(_month = d._month) &&
			(_day = d._day);
	}
	bool operator!=(const Date&d)
	{
		return (_year != d._year) &&
			(_month != d._month) &&
			(_day != d._day);
	}
	bool operator>(const Date& d)
	{
		if ((d._year < _year) || (d._month < _month) || (d._day < _day))
		{
			return true;
		}
		else
			return false;
	}
	bool operator<(const Date& d)
	{
		if ((d._year > _year) || (d._month > _month) || (d._day > _day))
		{
			return true;
		}
		else
			return false;
	}
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date c1;
	c1.display();
	Date c2(1900, 1, 1);
	c2.display();
	Date c3;
	c3 = c2;
	c3.display();
	c3 = c1++;
	c3.display();
	c3 = ++c1;
	c3.display();
	cout << "�����ڼ�����" << endl;
	cout << (c3 - c2) << endl;
	Date c4 = c1 + 30;
	Date c5;
	c5.IsInvalid(1900, 1, 36);
	c5.display();
	bool state;
	cout << "�����ڱȽ�" << endl;
	Date d4(2016, 10, 1);
	Date d5(2016, 10, 10);
	state=(d4 < d5);
	cout << state << endl;
	state=(d4 == d5);
	cout << state << endl;
	state = (d4 != d5);
	cout << state << endl;
	system("pause");

}