#pragma once

//实现一个函数，将字符串中每个空格替换为%20，在一个字符串上进行操作
//输入"We are heppy."，输出"We%20are%20heppy."

#include <iostream>
#include <assert.h>
using namespace std;	

//str[] 是字符数组，size是数组容量
void RepalceBlank(char str[], int size)
{
	assert(str);
	assert(size > 0);
	
	//originalSize是字符数组实际的长度
	int numOfBlank = 0;
	int originalSize = 0;
	int i = 0;

	while (str[i])
	{
		originalSize++;

		if (str[i] == ' ')
			numOfBlank++;

		i++;
	}

	int newSize = originalSize + numOfBlank * 2;

	//扩展后的数组长度大于字符数组的容量，就返回
	if (newSize > size)
		return;

	//如果newSize小于originalSize，数组中就没有空格了
	while (newSize && newSize > originalSize)
	{
		if (str[originalSize] != ' ')
			str[newSize] = str[originalSize];
		else
		{
			str[newSize--] = '0';
			str[newSize--] = '2';
			str[newSize] = '%';
		}

		newSize--;
		originalSize--;
	}
}

void TestRepalceBlank()
{
	char str[30] = "I am a student.";
	cout << str << endl;

	RepalceBlank(str, sizeof(str)/sizeof(str[0]));
	cout << str << endl;
}
