// C++ program to demonstrate lambda expression in C++
#include <bits/stdc++.h>
#include <iostream>


int main()
{
   	int count{0};

	std::vector<int> vec {1, 2, 88, 78};
	std::vector<int> vec2 {4, 5, 6};
	
	//unfortunately, you need an external variable for index
	std::generate(vec.begin(),vec.end(),[&count]{
		count++;
		return count*count;
	});

	std::cout << vec[4] << std::endl;

	
	//sort wants a function that accepts two parameters and compares them
	std::sort(vec.begin(),vec.end(),[](int x,int y){return x>y;});
	
	//for_each can be replaced by a range loop usually
	std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<std::endl;});

	std::cout<<"second part" << std::endl;

	std::transform(vec.begin(),vec.end(),vec2.begin(),[](int& x){return x+2;});
	std::cout << vec2[1] << std::endl;
}
