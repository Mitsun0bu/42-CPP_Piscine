/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:16 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/23 10:01:56 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ CONSTRUCTOR ~~~                              */
/*                                                                            */
/* ************************************************************************** */

PmergeMe::PmergeMe(void)
{
    // std::cout   << YELLOW
    //             << "[CONSTRUCTOR] : PmergeMe created"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ COPY CONSTRUCTOR ~~~                           */
/*                                                                            */
/* ************************************************************************** */

PmergeMe::PmergeMe(PmergeMe const & src)
{
    *this = src;
}

/* ************************************************************************** */
/*                                                                            */
/*                   ~~~ ASSIGNMENT OPERATOR OVERLOAD ~~~                     */
/*                                                                            */
/* ************************************************************************** */

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
    if (this != &src)
    {
        this->input_vector  = src.input_vector;
        this->input_list    = src.input_list;
        this->sorted_vector = src.sorted_vector;
        this->sorted_list   = src.sorted_list;
        this->vector_time   = src.vector_time;
        this->list_time     = src.list_time;
    }
    return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                           ~~~ DESTRUCTOR ~~~                               */
/*                                                                            */
/* ************************************************************************** */

PmergeMe::~PmergeMe(void)
{
    // std::cout   << YELLOW
    //             << "[DESTRUCTOR] : PmergeMe destroyed"
    //             << END
    //             << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                         ~~~ PUBLIC METHODS ~~~                             */
/*                                                                            */
/* ************************************************************************** */

void PmergeMe::parseArguments(int ac, char** av)
{
    int num = 0;

    if (ac < 2)
        throw (MissingArgumentError());   

    for (int i = 1; i < ac; ++i)
    {
        try
        {
            num = std::stoi(av[i]);
        }
        catch (...)
        {
            throw (NonIntError());
        }
        if (num < 0) 
            throw (NegativeIntError());
        input_vector.push_back(num);
        input_list.push_back(num);
    }
}

void PmergeMe::process()
{
    clock_t         start;
    clock_t         end;

    start           = clock();
    sorted_vector   = getSortedVector(input_vector);
    end             = clock();
    vector_time     = static_cast<double>(end - start);

    start           = clock();
    sorted_list     = getSortedList(input_list);
    end             = clock();
    list_time       = static_cast<double>(end - start);
}

void PmergeMe::printResults()
{
    std::cout << YELLOW << "[BEFORE SORT]\t\t\t: " << END;    
    for (std::vector<int>::iterator it = input_vector.begin(); it != input_vector.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    std::cout << GREEN << "[AFTER SORT - VECTOR]\t\t: " << END;
    for (std::vector<int>::iterator it = sorted_vector.begin(); it != sorted_vector.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    std::cout << GREEN << "[AFTER SORT - LIST]\t\t: " << END;
    for (std::list<int>::iterator it = sorted_list.begin(); it != sorted_list.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    std::cout   << ORANGE << "[STD::VECTOR PERFORMANCE]\t: "  << END
                << vector_time << " us "
                << "(" << input_vector.size() << " elements)"
                << std::endl;

    std::cout   << ORANGE << "[STD::LIST PERFORMANCE]\t\t: " << END 
                << list_time << " us "
                << "(" << input_list.size() << " elements)"
                << std::endl
                << std::endl;
}

void PmergeMe::printCaughtError(const std::exception& e)
{
    std::cout   << RED
                << "[ERROR]\t\t\t\t: "
                << e.what()
                << END
                << std::endl;
}

void PmergeMe::printUsage()
{
    std::cout   << BLUE
                << "[USAGE]\t\t\t\t: ./PmergeMe [int] [int] [int] ..."
                << END
                << std::endl
                << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                      ~~~ PRIVATE METHODS : VECTOR ~~~                      */
/*                                                                            */
/* ************************************************************************** */

std::vector<int> PmergeMe::getSortedVector(const std::vector<int>& input)
{
    std::vector<int>    sorted(input);

    recursiveMergeSortAlgorithm(sorted, 0, sorted.size() - 1);

    return (sorted);
}

void PmergeMe::recursiveMergeSortAlgorithm(std::vector<int>& input, int left, int right)
{
    if (right - left <= THRESHOLD)
        insertSortVector(input, left, right);
    else
    {
        int mid = left + (right - left) / 2;
        recursiveMergeSortAlgorithm(input, left, mid);
        recursiveMergeSortAlgorithm(input, mid + 1, right);
        mergeSortVector(input, left, mid, right);
    }
}

void PmergeMe::insertSortVector(std::vector<int>& input, int left, int right)
{
    // ITERATE FROM SECOND TO LAST ELEMENT
    for (int i_current = left + 1; i_current <= right; ++i_current)
    {
        int current_value    = input[i_current];
        int i_previous      = i_current - 1;

        // SHIFT ELEMENTS GREATER THAN THE CURRENT ONE TO THE RIGHT
        while (i_previous >= left && input[i_previous] > current_value)
        {
            input[i_previous + 1] = input[i_previous];
            i_previous--;
        }
        // INSERT THE CURRENT ELEMENT IN THE RIGHT PLACE
        input[i_previous + 1] = current_value;
    }
}

void PmergeMe::mergeSortVector(std::vector<int>& input, int left, int mid, int right)
{
    // CALCULATE THE SIZE OF THE SUBARRAYS
    int leftArraySize   = mid - left + 1;
    int rightArraySize  = right - mid;

    // CREATE THE SUBARRAYS
    std::vector<int> leftArray(leftArraySize);
    std::vector<int> rightArray(rightArraySize);

    // COPY ELEMENTS FROM INPUT TO THE SUBARRAYS
    for (int i = 0; i < leftArraySize; ++i)
        leftArray[i] = input[left + i];
    for (int i = 0; i < rightArraySize; ++i)
        rightArray[i] = input[mid + 1 + i];

    // MERGE SUBARRAYS BACK TO INPUT
    int i_left   = 0;
    int i_right  = 0;
    int i_input  = left;
    while (i_left < leftArraySize && i_right < rightArraySize)
    {
        if (leftArray[i_left] <= rightArray[i_right])
            input[i_input++] = leftArray[i_left++];
        else
            input[i_input++] = rightArray[i_right++];
    }

    // COPY ANY REMAINING ELEMENTS FROM THE SUBARRAYS
    while (i_left < leftArraySize)
        input[i_input++] = leftArray[i_left++];
    while (i_right < rightArraySize)
        input[i_input++] = rightArray[i_right++];
}

/* ************************************************************************** */
/*                                                                            */
/*                       ~~~ PRIVATE METHODS : LIST ~~~                       */
/*                                                                            */
/* ************************************************************************** */

std::list<int> PmergeMe::getSortedList(const std::list<int>& input)
{
    std::list<int> sorted(input);

    recursiveMergeSortAlgorithm(sorted, sorted.begin(), --sorted.end());

    return (sorted);
}

void PmergeMe::recursiveMergeSortAlgorithm(std::list<int>& input, std::list<int>::iterator left, std::list<int>::iterator right)
{
    int distance = std::distance(left, right);
    
    if (distance <= 0)
        return;

    std::list<int>::iterator mid = left;
    std::advance(mid, distance / 2);

    std::list<int>::iterator mid_next = mid;
    std::advance(mid_next, 1);

    recursiveMergeSortAlgorithm(input, left, mid);
    recursiveMergeSortAlgorithm(input, mid_next, right);

    std::list<int>::iterator right_next = right;
    std::advance(right_next, 1);

    insertSortList(left, mid_next);
    insertSortList(mid_next, right_next);

    std::inplace_merge(left, mid_next, right_next);
}

void PmergeMe::insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (begin == end)
        return;

    std::list<int>::iterator current = begin;
    ++current;

    // ITERATE FROM SECOND TO LAST ELEMENT
    while (current != end)
    {
        int current_value = *current;
        std::list<int>::iterator previous = current;
        --previous;

        // SHIFT ELEMENTS GREATER THAN THE CURRENT ONE TO THE RIGHT
        while (previous != begin && *previous > current_value)
        {
            std::swap(*previous, *current);
            --previous;
            --current;
        }

        // HANDLE CASE WHERE CURRENT VALUE < FIRST ELEMENT OF THE LIST
        if (previous == begin && *previous > current_value)
            std::swap(*previous, *current);

        ++current;
    }
}