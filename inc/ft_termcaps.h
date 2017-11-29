/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:53:17 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 19:01:24 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAPS_H
# define FT_TERMCAPS_H

# define FTK_UP 4283163
# define FTK_DOWN 4348699
# define FTK_RIGHT 4414235
# define FTK_LEFT 4479771

# define FTK_NL 10
# define FTK_ESC 27
# define FTK_DEL 127
# define FTK_SP ' '
# define FTK_BRA '['
# define FTK_A 'a'
# define FTK_D 'd'
# define FTK_F 'f'
# define FTK_H 'h'
# define FTK_L 'l'
# define FTK_S 's'
# define FTK_SCH ':'

# define FT_TC_GETMPOS ("\033[6n")
# define FT_TC_REV ("mr") 
# define FT_TC_CLR ("me") 
# define FT_TC_ULON ("us")
# define FT_TC_ULOFF ("ue")
# define FT_TC_SC ("sc")
# define FT_TC_RC ("rc")
# define FT_TC_CD ("cd")
# define FT_TC_UP ("UP")
# define FT_TC_DO ("DO")
# define FT_TC_CM ("cm")
# define FT_TC_HO ("ho")
# define FT_TC_TI ("ti")
# define FT_TC_VI ("vi")
# define FT_TC_TE ("te")
# define FT_TC_VE ("ve")
# define FT_TC_CL ("cl")

# endif
