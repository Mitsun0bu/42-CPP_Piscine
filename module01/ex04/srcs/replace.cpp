/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:11:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/06 19:13:23 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/main.hpp"

void    replace(std::string infile_name, std::string old, std::string sub, std::string outfile_name)
{
    std::ifstream   infile(infile_name);
    if (infile)
    {
        if (replacing_loop(infile, old, sub, outfile_name) == DONE)
            std::cout << "Substitution done !" << std::endl;
        else
        {
            std::cout << "No occurence of \""
                        << old
                        << "\" in "
                        << infile_name << std::endl;
        }
    }
    else
        print_error(NO_INFILE);

    infile.close();

    return ;
}

int replacing_loop(std::ifstream &infile, std::string old, std::string sub, std::string outfile_name)
{
    std::ofstream   out_file(outfile_name);
    bool            n_subs = TO_DO;
    std::string     buffer = "";
    
    while (infile >> buffer)
    {
        if (buffer == old)
        {
            buffer = sub;
            n_subs = DONE;
        }
        out_file << buffer + " ";
    }

    out_file.close();

    return (n_subs);
}
