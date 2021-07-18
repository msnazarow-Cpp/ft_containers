#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iostream>

void vector_check_int()
    {
        
        std::vector<int> std_vec;
        std_vec.push_back(1);
        std_vec.push_back(41);
        std_vec.push_back(-71);
        std_vec.push_back(8);
        ft::vector<int> ft_vec(std_vec.begin(), std_vec.end());
        std::cout << "ft: " << *ft_vec.begin()  << " | std: " << *std_vec.begin() << std::endl;
        std::cout << "ft: " << *(ft_vec.end() - 1)  << " | std: " << *(std_vec.end() - 1) << std::endl;
        std::cout << "ft: " << *ft_vec.rbegin()  << " | std: " << *std_vec.rbegin() << std::endl;
        std::cout << "ft: " << *(ft_vec.rend() - 1)  << " | std: " << *(std_vec.rend() - 1) << std::endl;
        std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << ft_vec.max_size()  << " | std: " << std_vec.max_size() << std::endl;
        std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        ft_vec.resize(10);
        std_vec.resize(10);
        std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << ft_vec.empty()  << " | std: " << std_vec.empty() << std::endl;
        ft_vec.reserve(40);
        std_vec.reserve(40);
        std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        std::cout << "ft: " << ft_vec[1]  << " | std: " << std_vec[1] << std::endl;
        std::cout << "ft: " << ft_vec.at(2) << " | std: " << std_vec.at(2) << std::endl;
        std::cout << "ft: " << ft_vec.front()  << " | std: " << std_vec.front() << std::endl;
        std::cout << "ft: " << ft_vec.back()  << " | std: " << std_vec.back() << std::endl;
        ft_vec.insert(ft_vec.begin(), 99);
        std_vec.insert(std_vec.begin(), 99);
        std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        ft_vec.erase(ft_vec.begin());
        std_vec.erase(std_vec.begin());
        std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        ft::vector<int> ft_swap(10,10);
        ft::vector<int>::iterator it = ft_swap.begin();
        ft_vec.swap(ft_swap);
        std::cout << "ft: " << (*(it + 2)) << std::endl;
        std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
        ft::vector<int>::const_iterator cit = ft_swap.begin() + 3;
        std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
        ft_swap.clear();
        std_vec.clear();
        std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << (ft_vec > ft_swap) << std::endl;;
       
    }
void vector_check_string()
    {
        
        std::vector<std::string> std_vec;
        std_vec.push_back("Bob");
        std_vec.push_back("Freddy");
        std_vec.push_back("Layla");
        std_vec.push_back("Kevin");
        ft::vector<std::string> ft_vec(std_vec.begin(), std_vec.end());
        std::cout << "ft: " << *ft_vec.begin()  << " | std: " << *std_vec.begin() << std::endl;
        std::cout << "ft: " << *(ft_vec.end() - 1)  << " | std: " << *(std_vec.end() - 1) << std::endl;
        std::cout << "ft: " << *ft_vec.rbegin()  << " | std: " << *std_vec.rbegin() << std::endl;
        std::cout << "ft: " << *(ft_vec.rend() - 1)  << " | std: " << *(std_vec.rend() - 1) << std::endl;
        std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << ft_vec.max_size()  << " | std: " << std_vec.max_size() << std::endl;
        std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        ft_vec.resize(10);
        std_vec.resize(10);
        std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << ft_vec.empty()  << " | std: " << std_vec.empty() << std::endl;
        ft_vec.reserve(40);
        std_vec.reserve(40);
        std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        std::cout << "ft: " << ft_vec[1]  << " | std: " << std_vec[1] << std::endl;
        std::cout << "ft: " << ft_vec.at(2) << " | std: " << std_vec.at(2) << std::endl;
        std::cout << "ft: " << ft_vec.front()  << " | std: " << std_vec.front() << std::endl;
        std::cout << "ft: " << ft_vec.back()  << " | std: " << std_vec.back() << std::endl;
        ft_vec.insert(ft_vec.begin(), "Josh");
        std_vec.insert(std_vec.begin(), "Josh");
        std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        ft_vec.erase(ft_vec.begin());
        std_vec.erase(std_vec.begin());
        std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        ft::vector<std::string> ft_swap(10, "Billy");
        ft::vector<std::string>::iterator it = ft_swap.begin();
        ft_vec.swap(ft_swap);
        std::cout << "ft: " << (*(it + 2)) << std::endl;
        std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
        ft::vector<std::string>::const_iterator cit = ft_swap.begin() + 3;
        std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
        ft_swap.clear();
        std_vec.clear();
        std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << (ft_vec > ft_swap) << std::endl;
    }

void map_check_int()
    {
        std::map<std::string, int> std_vec;
        std_vec["Billy"] = 1;
        std_vec["Freddy"] = 41;
        std_vec["Kianu"] = -71;
        std_vec["Yetti"] = 8;
        ft::map<std::string, int> ft_vec;
        ft_vec["Billy"] = 1;
        ft_vec["Freddy"] = 41;
        ft_vec["Kianu"] = -71;
        ft_vec["Yetti"] = 8;
        std::cout << "ft: " << (*ft_vec.begin()).first << " " << (*ft_vec.begin()).second  << " | std: " << (*std_vec.begin()).first << " " <<  (*std_vec.begin()).second << std::endl;
        std::cout << "ft: " << (*ft_vec.end()).first << " " << (*ft_vec.end()).second  << " | std: " << (*std_vec.end()).first << " " <<  (*std_vec.end()).second << std::endl;
        std::cout << "ft: " << (*ft_vec.rbegin()).first << " " << (*ft_vec.rbegin()).second  << " | std: " << (*std_vec.rbegin()).first << " " <<  (*std_vec.rbegin()).second << std::endl;
        std::cout << "ft: " << (*ft_vec.rend()).first << " " << (*ft_vec.rend()).second  << " | std: " << (*std_vec.rend()).first << " " <<  (*std_vec.rend()).second << std::endl;
       
        std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        std::cout << "ft: " << ft_vec.max_size()  << " | std: " << std_vec.max_size() << std::endl;
        ft_vec.insert(ft::pair<int, std::string>(10, "Boris"));
       std_vec.insert(std::pair<int, std::string>(10, "Boris"));
        
        // std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        // std::cout << "ft: " << ft_vec.empty()  << " | std: " << std_vec.empty() << std::endl;
        // ft_vec.reserve(40);
        // std_vec.reserve(40);
        // std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        // std::cout << "ft: " << ft_vec[1]  << " | std: " << std_vec[1] << std::endl;
        // std::cout << "ft: " << ft_vec.at(2) << " | std: " << std_vec.at(2) << std::endl;
        // std::cout << "ft: " << ft_vec.front()  << " | std: " << std_vec.front() << std::endl;
        // std::cout << "ft: " << ft_vec.back()  << " | std: " << std_vec.back() << std::endl;
        // ft_vec.insert(ft_vec.begin(), 99);
        // std_vec.insert(std_vec.begin(), 99);
        // std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        // ft_vec.erase(ft_vec.begin());
        // std_vec.erase(std_vec.begin());
        // std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        // ft::vector<int> ft_swap(10,10);
        // ft::vector<int>::iterator it = ft_swap.begin();
        // ft_vec.swap(ft_swap);
        // std::cout << "ft: " << (*(it + 2)) << std::endl;
        // std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
        // ft::vector<int>::const_iterator cit = ft_swap.begin() + 3;
        // std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
        // ft_swap.clear();
        // std_vec.clear();
        // std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vec.size() << std::endl;
        // std::cout << "ft: " << (ft_vec > ft_swap) << std::endl;;
       
    }
void map_check_string()
    {
        
        // std::map<int, std::string> std_vec;
        // std_vec.push_back("Bob");
        // std_vec.push_back("Freddy");
        // std_vec.push_back("Layla");
        // std_vec.push_back("Kevin");
        // ft::vector<std::string> ft_vec(std_vec.begin(), std_vec.end());
        // std::cout << "ft: " << *ft_vec.begin()  << " | std: " << *std_vec.begin() << std::endl;
        // std::cout << "ft: " << *(ft_vec.end() - 1)  << " | std: " << *(std_vec.end() - 1) << std::endl;
        // std::cout << "ft: " << *ft_vec.rbegin()  << " | std: " << *std_vec.rbegin() << std::endl;
        // std::cout << "ft: " << *(ft_vec.rend() - 1)  << " | std: " << *(std_vec.rend() - 1) << std::endl;
        // std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        // std::cout << "ft: " << ft_vec.max_size()  << " | std: " << std_vec.max_size() << std::endl;
        // std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        // ft_vec.resize(10);
        // std_vec.resize(10);
        // std::cout << "ft: " << ft_vec.size()  << " | std: " << std_vec.size() << std::endl;
        // std::cout << "ft: " << ft_vec.empty()  << " | std: " << std_vec.empty() << std::endl;
        // ft_vec.reserve(40);
        // std_vec.reserve(40);
        // std::cout << "ft: " << ft_vec.capacity()  << " | std: " << std_vec.capacity() << std::endl;
        // std::cout << "ft: " << ft_vec[1]  << " | std: " << std_vec[1] << std::endl;
        // std::cout << "ft: " << ft_vec.at(2) << " | std: " << std_vec.at(2) << std::endl;
        // std::cout << "ft: " << ft_vec.front()  << " | std: " << std_vec.front() << std::endl;
        // std::cout << "ft: " << ft_vec.back()  << " | std: " << std_vec.back() << std::endl;
        // ft_vec.insert(ft_vec.begin(), "Josh");
        // std_vec.insert(std_vec.begin(), "Josh");
        // std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        // ft_vec.erase(ft_vec.begin());
        // std_vec.erase(std_vec.begin());
        // std::cout << "ft: " << ft_vec[0]  << " | std: " << std_vec[0] << std::endl;
        // ft::vector<std::string> ft_swap(10, "Billy");
        // ft::vector<std::string>::iterator it = ft_swap.begin();
        // ft_vec.swap(ft_swap);
        // std::cout << "ft: " << (*(it + 2)) << std::endl;
        // std::cout << "ft: " << (*(ft_swap.begin() + 2)) << std::endl;
        // ft::vector<std::string>::const_iterator cit = ft_swap.begin() + 3;
        // std::cout << "ft: " << ((ft_swap.begin() + 2) > cit) << std::endl;
        // ft_swap.clear();
        // std_vec.clear();
        // std::cout << "ft: " << ft_swap.size()  << " | std: " << std_vec.size() << std::endl;
        // std::cout << "ft: " << (ft_vec > ft_swap) << std::endl;
    }
int main()
{
    std::cout << "================vector_int==============" << std::endl;
    vector_check_int();
    std::cout << "================vector_string==============" << std::endl;
    vector_check_string();
    std::cout << "================map_int==============" << std::endl;
    map_check_int();
    std::cout << "================map_string==============" << std::endl;
    map_check_string();
    return 0;
}
