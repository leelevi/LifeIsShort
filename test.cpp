#include"test.h"
using namespace std;
void load_data(std::string file_path , std::vector<int>& out)
{
	ifstream  infile(file_path);
	if (!infile.is_open())
		return;
	while (!infile.eof()) {
		int a;
		infile >> a;
		out.push_back(a);
	}
	return;
}
void load_data_array(std::string file_path, int* a)
{
	ifstream  infile(file_path);
	if (!infile.is_open())
		return;
	int i = 0;
	while (!infile.eof()) {
		infile >> a[i];
		i++;
	}
	return;
}
void MergeSort(std::vector<int> &input_array)
{
	//分位,中间数
	if (input_array.size() > 1) {
		int mid = input_array.size() / 2;
		std::vector<int> output;
		std::vector<int>::iterator iter = input_array.begin();
		std::vector<int> left_array;
		std::vector<int> right_array;
		while (iter != input_array.end())
		{
			if (left_array.size() < (unsigned)mid)
				left_array.push_back(*iter);
			else
				right_array.push_back(*iter);
			iter++;
		}
		MergeSort(left_array);
		MergeSort(right_array);
		Merge(output, left_array, right_array);
		input_array = output;
	}
}

void Merge(std::vector<int>& output, std::vector<int> left, std::vector<int> right)
{
	vector<int>::iterator left_iter = left.begin();
	vector<int>::iterator right_iter = right.begin();
	while (left_iter != left.end() || right_iter != right.end())
	{
		if (right_iter == right.end())
		{
			output.push_back(*left_iter);
			left_iter++;
		}
		else if (left_iter == left.end())
		{
			output.push_back(*right_iter);
			right_iter++;
		}
		else {
			if (*left_iter < *right_iter) {
				output.push_back(*left_iter);
				left_iter++;
			}
			else {
				output.push_back(*right_iter);
				right_iter++;
			}
		}
	}

}
int countReverse(std::vector<int> &input_array)
{
	//分位,中间数
	if (input_array.size() > 1) {
		int mid = input_array.size() / 2;
		int count_pre =0, count_now = 0;
		std::vector<int> output;
		std::vector<int>::iterator iter = input_array.begin();
		std::vector<int> left_array;
		std::vector<int> right_array;
		while (iter != input_array.end())
		{
			if (left_array.size() < (unsigned)mid)
				left_array.push_back(*iter);
			else
				right_array.push_back(*iter);
			iter++;
		}
		count_pre = countReverse(left_array)+countReverse(right_array);
		count_now = mergeReverse(output, left_array, right_array);
		input_array = output;
		return count_pre + count_now;
	}
	else
		return 0;
}
int mergeReverse(std::vector<int>& output, std::vector<int> left, std::vector<int> right)
{
	vector<int>::iterator left_iter = left.begin();
	vector<int>::iterator right_iter = right.begin();
	long long inv_count = 0;
	int mid = left.size();
	int i = 0;
	while (left_iter != left.end() || right_iter != right.end())
	{
		if (right_iter == right.end())
		{
			output.push_back(*left_iter);
			left_iter++;
					
		}
		else if (left_iter == left.end())
		{
			output.push_back(*right_iter);
			right_iter++;
		}
		else {
			if (*left_iter < *right_iter) {
				output.push_back(*left_iter);
				left_iter++;
				i++;
			}
			else {
				output.push_back(*right_iter);
				right_iter++;
				inv_count = inv_count + (mid - i);
			}
			
		}
	}
	//cout << count << " ";
	return inv_count;
}