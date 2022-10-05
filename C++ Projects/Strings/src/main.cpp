#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string_view>
#include<sstream>
#include<cstring>

bool isEquals( std::string& a,  std::string& b)
{
	//return a < b;
	
	return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), \
	[](unsigned char x, unsigned char y)
	{
		return std::tolower(x)<std::tolower(y);
	});	
	
	//return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin(), [](auto a, auto b){return std::tolower(a)==std::tolower(b);}); // have to check it is not working
}




/*bool iequals(const std::string& a, const std::string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}*/
template<typename T>
void print(T& contain)
{
	for(auto& x : contain)
	{
		
		std::cout<<x<<'\n';
	}
	std::cout<<std::endl;
	
}

#if 0
int main()
{
	std::stringstream str ("hemant tailor aa a aaabb aaaaab aaabbbb aaaaaa");
	//std::stringstream str(obj);
	std::string tok;
	std::vector<std::string> v;
	while(std::getline(str, tok , ' '))
	{
		v.push_back(tok);
	}
	print(v);
	std::sort(v.begin(), v.end(), isEquals);
	print(v);
}

#endif


#if 1

template<typename T>
bool binary_predicate(const T& a, const T& b)  
{
	return a < b; 
}

template<>
bool binary_predicate<std::string>(const std::string& a,  const std::string& b)
{
	// case sensitive
	return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),\
	std::less<unsigned char>());
	
							//OR
	// case insensitive
	/* return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),\
	[](unsigned char x, unsigned char y)
	{
		return std::tolower(x) < std::tolower(y);
	});*/
}

int main()
{
	std::stringstream ss("hemant is a good boy .");
	std::string token;
	std::vector<std::string> tokens;
	while(std::getline(ss, token, ' '))
	{
		tokens.push_back(token);
	}
	print(tokens);
	std::sort(tokens.begin(), tokens.end(), binary_predicate<std::string>);
	print(tokens);
	
	// std::stringstream sss;
	// for(auto& x : tokens)
	// {
	// 	sss<<x;
	// 	sss<<" ";
	// }
	// std::string temp(sss.str());
	// std::cout<<temp<<temp.size();

	std::string str1 = "hemant_tailor_hem";
	std::string str2 = "Pooja";
	
	// str1.append(str2, 2, 20);
	// std::cout<<str1;//hemant tailoroja

	// str1.replace(0, 6, str2);
	// std::cout<<str1;//Pooja_tailor_hem

	// str1.erase(7, 6);
	// std::cout<<str1;//hemant__hem

	// auto st = str1.substr(7,6);
	// std::cout<<st<<'\n';//tailor

	// if(str1.find("hem") != std::string::npos)
	// {
	// 	std::cout<<str1.find("hem"); //0 
	// }
	// if(str1.find("tai") != std::string::npos)
	// {
	// 	std::cout<<str1.find("tai"); //7
	// }
	// if(str1.find("ti") != std::string::npos)
	// {
	// 	std::cout<<str1.find("ti"); //7
	// }
	// std::cout<<str1.find("ti"); //18446744073709551615

	// char arr[70];//={' '};
	// std::cout<<strlen(arr);
	// str1.copy(arr, 6, 7);//tailor
	// std::cout<<arr;


	// if(str1.size() == str1.length())
	// {
	// 	std::cout<<"size and length return same value w/o including null "<<str1.length();
	// 	//size and length return same value w/o including null 17
	// }
	std::string obj1 = "Hemant", obj2 = "HemantTailorq"; 
	std::string_view sv = obj1.substr(1,3);
	std::cout<<obj1.compare(obj2); //-7
	std::cout<< sv<<'\n'<<sizeof(sv);

}
#endif