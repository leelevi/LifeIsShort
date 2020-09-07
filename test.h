#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
void load_data(std::string, std::vector<int>&);
void load_data_array(std::string, int*);
void MergeSort(std::vector<int> &);
void Merge(std::vector<int>&, std::vector<int>, std::vector<int>);
int countReverse(std::vector<int> &input_array);
int mergeReverse(std::vector<int>& output, std::vector<int> left, std::vector<int> right);