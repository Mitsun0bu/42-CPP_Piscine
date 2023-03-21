/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:16 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/21 18:49:39 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int ac, char** av)
{
    parseArguments(ac, av);
}

void PmergeMe::parseArguments(int ac, char** av)
{
    for (int i = 1; i < ac; ++i)
    {
        try
        {
            int num = std::stoi(av[i]);
            if (num < 1) 
                throw std::runtime_error("Error");
            input_vector.push_back(num);
            input_list.push_back(num);
        }
        catch (const std::exception& e)
        {
            throw std::runtime_error("Error");
        }
    }
}

void PmergeMe::process()
{
    sorted_vector   = mergeInsertSortVector(input_vector);
    sorted_list     = mergeInsertSortList(input_list);

    vector_time     = getTime(input_vector);
    list_time       = getTime(input_list);
}

void PmergeMe::printResults()
{
    std::cout << RED << "[BEFORE SORT]\t\t\t: " << END;    
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
                << std::endl;
}

std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& input)
{
    std::vector<int>    sorted(input);

    recursiveSortAlgorithm(sorted, 0, sorted.size() - 1);

    return (sorted);
}

void PmergeMe::recursiveSortAlgorithm(std::vector<int>& input, int left, int right)
{
    if (right - left <= THRESHOLD)
        insertSortVector(input, left, right);
    else
    {
        int mid = left + (right - left) / 2;
        recursiveSortAlgorithm(input, left, mid);
        recursiveSortAlgorithm(input, mid + 1, right);
        mergeSortVector(input, left, mid, right);
    }
}

void PmergeMe::insertSortVector(std::vector<int>& input, int left, int right)
{
    // ITERATE FROM SECOND TO LAST ELEMENT
    for (int i_current = left + 1; i_current <= right; ++i_current)
    {
        int currentValue    = input[i_current];
        int i_previous      = i_current - 1;

        // SHIFT ELEMENTS GREATER THAN THE CURRENT ONE TO THE RIGHT
        while (i_previous >= left && input[i_previous] > currentValue)
        {
            input[i_previous + 1] = input[i_previous];
            i_previous--;
        }
        // INSERT THE CURRENT ELEMENT IN THE RIGHT PLACE
        input[i_previous + 1] = currentValue;
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

std::list<int> PmergeMe::mergeInsertSortList(const std::list<int>& input)
{
    std::list<int> sorted(input);

    recursiveSortAlgorithm(sorted, sorted.begin(), --sorted.end());

    return (sorted);
}

void PmergeMe::recursiveSortAlgorithm(std::list<int>& input, std::list<int>::iterator left, std::list<int>::iterator right)
{
    int distance = std::distance(left, right);
    
    if (distance <= 0)
        return;

    std::list<int>::iterator mid = left;
    std::advance(mid, distance / 2);

    std::list<int>::iterator mid_next = mid;
    std::advance(mid_next, 1);

    recursiveSortAlgorithm(input, left, mid);
    recursiveSortAlgorithm(input, mid_next, right);

    std::list<int>::iterator right_next = right;
    std::advance(right_next, 1);

    insertSortList(left, mid_next);
    insertSortList(mid_next, right_next);

    std::inplace_merge(left, mid_next, right_next);
}

void PmergeMe::insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (begin == end) return;

    std::list<int>::iterator current = begin;
    ++current;

    while (current != end)
    {
        int currentValue = *current;
        std::list<int>::iterator previous = current;
        --previous;

        while (previous != begin && *previous > currentValue)
        {
            std::swap(*previous, *current);
            --previous;
            --current;
        }

        if (previous == begin && *previous > currentValue)
            std::swap(*previous, *current);

        ++current;
    }
}

template <typename Container>
double PmergeMe::getTime(const Container& input)
{
    (void) input;
    // std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    return (0);
}
