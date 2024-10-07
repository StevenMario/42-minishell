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

#include "libft/libft.h"
#include "minishell.h"
//#include <cstddef>

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

void  ft_echo(t_data *mish, t_cmd cmd)
{
  int i;
  int flag;

  i = 1;
  flag = 0;

  while (cmd.all_cmd[i] != NULL)
  {
    if (iof_flag(cmd.all_cmd[i]) == 1 || flag == 1)
    {
      flag = 1;
      ft_printf("%s", cmd.all_cmd[i]);
      if (cmd.all_cmd[i + 1] != NULL)
        ft_printf(" ");
    }
    i++;
  }
  if (iof_flag(cmd.all_cmd[1]) == 1)
    ft_printf("\n");
}
