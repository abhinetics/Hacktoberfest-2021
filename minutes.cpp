
				num1.push_back(time_str[x]);
				num1.push_back(time_str[x + 1]);
			}

			if (colon && isdigit(time_str[x]))
			{
				min1.push_back(time_str[x]);
			}
			else if (isdigit(time_str[x]))
			{
				hr1.push_back(time_str[x]);
			}
		}
	}

	int hr = 0;
	if (stoi(hr1) == stoi(hr2) && num1 == num2 && stoi(min1) > stoi(min2))
	{
		hr = 24 - (stoi(hr1) - stoi(hr2));
	}
	else if (stoi(hr1) > stoi(hr2) && num1 == num2 && stoi(min1) < stoi(min2))
	{
		hr = 24 - (stoi(hr1) - stoi(hr2));
	}
	else if (num1 == num2 || (hr2 == "12" && hr1 != "12"))
	{
		hr = stoi(hr2) - stoi(hr1);
	}
	else
	{
		hr = (12 - stoi(hr1)) + stoi(hr2);
	}

	int time;
	if (min1 != "00")
	{
		time = (hr * 60 - stoi(min1)) + stoi(min2);
	}
	else
	{
		time = (hr * 60 + stoi(min1)) + stoi(min2);
	}

	return time;
}

int main() {

	cout << "Minutes between 12:01AM to 12:00PM: "<< count_minutes("12:01PM-12:00PM") << endl;
	cout << "Minutes between 2:12AM to 2:8AM: "<< count_minutes("2:12AM-2:8AM") << endl;
	cout << "Minutes between 1:04PM to 1:29PM: "<< count_minutes("1:04PM-1:29PM") << endl;
	cout << "Minutes between 2:00PM to 10:00PM: "<< count_minutes("2:00PM-10:00PM") << endl;
	return 0;
}
