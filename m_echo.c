// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   m_echo.c                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: irabesan <irabesan@student.42antananarivo  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/09/25 11:29:31 by irabesan          #+#    #+#             //
//   Updated: 2024/09/25 11:40:34 by irabesan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "minishell.h"

int iof_flag(char *echo)
{
  int i;

  if (!echo)
    return (0);
  if (echo[0] != '-' || echo[1] != 'n')
    return (0);
  i = 1;
  while (echo[i] != '\0')
  {
    if (echo[i] != 'n')
      return (0);
    i++;
  }
  return (1);
}

