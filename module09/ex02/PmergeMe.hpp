/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:11 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/21 18:46:13 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <stdexcept>
#include <string>

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define END "\033[0m"

# define THRESHOLD 10

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class PmergeMe
{
    public:

                PmergeMe(int ac, char** av);
        void    process();
        void    printResults();

    private:

        std::vector<int>    input_vector;
        std::list<int>      input_list;
        std::vector<int>    sorted_vector;
        std::list<int>      sorted_list;
        double              vector_time;
        double              list_time;

        void                parseArguments(int ac, char** av);

        std::vector<int>    mergeInsertSortVector(const std::vector<int>& input);
        void                recursiveSortAlgorithm(std::vector<int>& input, int left, int right);
        void                insertSortVector(std::vector<int>& input, int left, int right);
        void                mergeSortVector(std::vector<int>& input, int left, int mid, int right);

        std::list<int>      mergeInsertSortList(const std::list<int>& input);
        void                recursiveSortAlgorithm(std::list<int>& input, std::list<int>::iterator left, std::list<int>::iterator right);
        void                insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end);

        template <typename Container>
        double              getTime(const Container& input);
};

#endif