/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:11 by llethuil          #+#    #+#             */
/*   Updated: 2023/03/23 10:01:53 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ INCLUDES ~~~                                */
/*                                                                            */
/* ************************************************************************** */

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

#define RED         "\x1B[31m"
#define GREEN       "\x1B[32m"
#define YELLOW      "\x1B[33m"
#define ORANGE      "\x1B[34m"
#define PURPLE      "\x1B[35m"
#define BLUE        "\x1B[36m"
#define END         "\033[0m"

#define THRESHOLD   10

/* ************************************************************************** */
/*                                                                            */
/*                        ~~~ EXCEPTIONS DEFINITION ~~~                       */
/*                                                                            */
/* ************************************************************************** */

class MissingArgumentError : public std::runtime_error
{
    public:
        MissingArgumentError() : std::runtime_error("MISSING ARGUMENT") {}
};

class NonIntError : public std::runtime_error
{
    public:
        NonIntError() : std::runtime_error("NON-INT VALUE IN INPUT LIST") {}
};

class NegativeIntError : public std::runtime_error
{
    public:
        NegativeIntError() : std::runtime_error("NEGATIVE INT IN INPUT LIST") {}
};

/* ************************************************************************** */
/*                                                                            */
/*                            ~~~ CLASS DEFINITION ~~~                        */
/*                                                                            */
/* ************************************************************************** */

class PmergeMe
{
    public:

		/* CONSTRUCTOR */
                            PmergeMe(void);
		/* COPY CONSTRUCTOR */
                            PmergeMe(const PmergeMe& src);
        /* ASSIGNMENT OPERATOR OVERLOAD */
        PmergeMe&           operator=(const PmergeMe& src);
        /* DESTRUCTOR */
                            ~PmergeMe(void);
        
        /* PUBLIC METHODS */
        void                parseArguments(int ac, char** av);
        void                process();
        void                printResults();
        void                printCaughtError(const std::exception& e);
        void                printUsage();

    private:

        /* PRIVATE ATTRIBUTES */
        std::vector<int>    input_vector;
        std::list<int>      input_list;
        std::vector<int>    sorted_vector;
        std::list<int>      sorted_list;
        double              vector_time;
        double              list_time;

        /* PRIVATE METHODS */
        
        /* VECTOR */
        std::vector<int>    getSortedVector(const std::vector<int>& input);
        void                recursiveMergeSortAlgorithm(std::vector<int>& input, int left, int right);
        void                insertSortVector(std::vector<int>& input, int left, int right);
        void                mergeSortVector(std::vector<int>& input, int left, int mid, int right);
        
        /* LIST */
        std::list<int>      getSortedList(const std::list<int>& input);
        void                recursiveMergeSortAlgorithm(std::list<int>& input, std::list<int>::iterator left, std::list<int>::iterator right);
        void                insertSortList(std::list<int>::iterator begin, std::list<int>::iterator end);
};

#endif