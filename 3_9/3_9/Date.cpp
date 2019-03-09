#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year <= 0 || month > 12 || month < 1
			|| day <= 0 || day > getMonthDay(year, month))
		{
			cout << "非法日期!, 日期已设为默认值：1900-1-1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}

		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2)
		{
			//判断闰年
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				day += 1;
		}
		return day;
	}
	// return Date += 2;
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		// 1900-1-1 + 32   1-33   33 - 31 = 2   1900-2-2
		_day += day;
		//考虑是否进位
		while (_day > getMonthDay(_year, _month))
		{
			_day -= getMonthDay(_year, _month);
			++_month;
			// 判断当前月份是否合理
			if (_month == 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
			//return *this;
		}
		// 1900-1-1  28    -57  --> 1989-12-4
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_month = 12;
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}

		return *this;
	}
	//Date& operator=(const Date& d);
	Date operator+(int days)
	{
		// Date + days   c = a + b
		Date ret(*this);
		ret += days;
		return ret;

	}
	Date operator-(int days)
	{
		Date ret(*this);
		ret -= days;
		return ret;
	}

	Date& operator++()
	{
		// ++Date  先自加，再返回
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date ret(*this);
		// Date++  先返回自加之前的值，再自加
		*this += 1;
		return ret;
	}
	Date& operator--()
	{
		// --Date
		*this -= 1;
		return *this;
	}
	Date operator--(int)
	{
		// Date--
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	// *this > d
	bool operator>(const Date& d)const
	{
		if (this->_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}
	bool operator>=(const Date& d)const
	{
		return (*this > d) || (*this == d);
	}
	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)const
	{
		return (*this < d) || (*this == d);
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}
	// *this - d
	int operator-(const Date& d)
	{
		Date ret(*this);
		int flag = 1;
		if (ret < d)
			flag = -1;
		int day = 0;
		if (ret < d)
		{
			while (ret < d)
			{
				++ret;
				++day;
			}
		}
		else
		{
			while (ret > d)
			{
				--ret;
				++day;
			}
		}

		return day * flag;
	}

	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void testDate()
{
	Date d1(2019, 1, 30);
	Date d2(2019, 2, 28);
	d1++;
	cout << "d1(2019, 1, 30) ++ :" << endl;
	d1.display();
	d2--;
	cout << "d2(2019, 2, 28) -- :" << endl;
	d2.display();
	Date d3 = d1 + 62;
	cout << "d1(2019, 1, 30)++ + 62: " << endl;
	d3.display();
	Date d4 = d2 - 39;
	cout << "d2(2019, 2, 28)-- - 39: " << endl;
	d4.display();

}

void testDate2()
{
	Date d1(2019, 3, 8);
	Date d2(2019, 1, 1);
	int d3 = d1 - d2;
	int d4 = d2 - d1;
	cout << "d1(2019, 3, 8) - d2(2019, 1, 1): " << d3 << endl;
	/*d3.display();*/
	cout << "d2(2019, 1, 1) - d1(2019, 3, 8): " << d4 << endl;
	/*d4.display();*/
	cout << "d1(2019, 3, 8) > d2(2019, 1, 1): " << (d1 > d2) << endl;
	cout << "d1(2019, 3, 8) >= d2(2019, 1, 1): " << (d1 >= d2) << endl;
	cout << "d1(2019, 3, 8) < d2(2019, 1, 1): " << (d1 < d2) << endl;
	cout << "d1(2019, 3, 8) <= d2(2019, 1, 1): " << (d1 <= d2) << endl;
	cout << "d1(2019, 3, 8) == d2(2019, 1, 1): " << (d1 == d2) << endl;
	cout << "d1(2019, 3, 8) != d2(2019, 1, 1): " << (d1 != d2) << endl;

}

int main()
{
	testDate();
	testDate2();
	system("pause");
	return 0;
}
