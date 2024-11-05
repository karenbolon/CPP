/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 16:34:41 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

//do not neet to close infile/outfile as it automatically happens when
//they go out of scope
//npos is used to check whether find() was successful.  If find() returns
//something, it means s1 was found and if it returns npos then s1 was NOT found
//c_str() converts the string to a const char * which is needed for open()
int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string		line;
		std::ifstream	infile;
		std::ofstream 	outfile;
		std::string s1 = av[2];
		std::string s2 = av[3];

		infile.open((av[1]));
		if (!infile)
		{
			std::cout << "ERROR: Could not open infile" <<std::endl;
			return (1);
		}
		outfile.open((std::string(av[1]) + ".replace").c_str());
		if (!outfile)
		{
			std::cout << "ERROR: Could not open outfile" <<std::endl;
			return (1);
		}
		while (getline(infile, line))
		{
			size_t	index = 0;
			while ((index = line.find(s1, index)) != std::string::npos)
			{
				line = line.substr(0, index) + s2 + line.substr(index + s1.length());
				index += s2.length(); 
			}
			outfile << line << std::endl;
		}
		if (infile.bad())
		{
			std::cout << "ERROR: Failure to read infile" << std::endl;
			return (1);
		}
		infile.close();
		outfile.close();
	}
	else
	{
		std::cout << "Usage: file S1 S2" << std::endl;
		return (1);
	}
	return (0);
}
