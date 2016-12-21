/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:11 by lchety            #+#    #+#             */
/*   Updated: 2016/12/21 17:41:02 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

typedef struct s_line_lst t_line_lst;
typedef struct s_proto t_proto;
typedef struct s_fd_lst t_fd_lst;

struct s_fd_lst
{
	int			fd;
	int			eof;
	char		*content;
	char		*tmp_line;
	t_fd_lst 	*next;
};

int		get_next_line(int, char**);

#endif

/*
	je cree la list fd si elle n existe pas deja

	je regarde si je trouve fd dans la liste (qu pire elle n existait pas et je return NULL donc tmp NULL)

	si tmp est NULL je cree un nouveau maillon dans la fd list.
		que j entre au dessus si la liste a d autres maillon
		et dans le ptr si elle vient d etre cree

	ensuite j appel get_line avec tmp comme ca j ai direct le bon fd
		et line ou je dois mettre ma nouvelle chaine.

		Dans get_line
			je verifie si list->content est NULL si il l est
				j appel add_content();
					je read dans le fd
						si ca marche
							je regarde si list->content contient quelque chose
								si oui je fais un strjoin
								sinon je fais un malloc et un strcpy
			je verifie si dans content on a un \n
				si oui
					j entre ca dans line et je free content...
				sinon je rappel get_line





Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut et i
	donc ce que je veux c est.

	get_line
		if j ai pas de lst_line
			j ai pas de content et donc je dois en creer un

		search dans content si il y a quelque chose

		couper content jusqu au \n et si on a tjrs pas de \n ni
		de content on read
		et si on arrive au EOF on l inscrit dans la struct




*/
/*

	if

*/

/*
	regarder si list eiste
		regarder si la list existe
		regarder si fd existe deja dans la list
			si non
				tmp = creat_new_maillon
			si oui
				tmp = fd_list

		find_nl in content
		regarder si on a un \n dans stock
					si oui
						envoyer chunk de stock

						return line
					else
						read  // ou gnl recursive

						liste

						0 Fariboles
						1 et les framboises ?\n
						2 roses
						3 vont les pot de fleurs
						4 alors ? comment

						send 4 free4 send 3 free3 send 2 free2


		j appel get_next_line
		regarde dans stock si y a un \n
		sinon read
		regarde dans stock si y a un \n


		creer buff
			copier dans stock
		delete buff
			envoyer bout de stock
		copier stock croper
			delete stock

*/
	/*
	donc on commence par verifier si on a le fd ou pas dans une list des fd
	*/
/*
	if fd already in list_fd
		if stock dont have \n
			read with buff size
		else
			return line
	else
		create fd save
			read
		if \n
			stock and return
		else
			read again


			push >
				buff
			 	buff
				buff
				buff
				buff
				buff > send strjoin buff + buff
								>> free

			push on top

			send and kill bottom


			push text





*/
/*
	Bon, je dois prendre une phrase jusqu a \n mais.. la taille du buffer peut etre n importe quoi...

	Je peux faire une list de buffer avec un bout de phrase a chaque fois ???
	ou une chaine lettre par lettre...

	hum

	du coup les variables static s initialise toutes seules a 0 ou null...

	donc je dois verifier si j ai deja le fd quelque part donc le sauvegarder

	ensuite je read sur le fd tant que j ai pas de \n et donc je fait un strjoin
	par exemple jusqu a trouver un \n
	ensuite je stock ce que j ai en trop

	du coup si j ai deja le fd j ai deja un truc en trop donc je fait un str join dessus si j ai pas un autre \n

	donc garder le nombre de char deja envoyer du fichier

	return 1 line lue
	return 0 termine
	return -1 erreur




*/
