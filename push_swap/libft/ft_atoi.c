/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:01 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/04 14:40:22 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str, int *overflow)
{
	int			i;
	long long	sign;
	long long	answer;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	answer = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	if ((answer * sign) > 2147483647 || (answer * sign) < -2147483648)
		*overflow = 0;
	return (answer * sign);
}

//#include <stdio.h>
//int main()
//{
//	char arr[15] = "2147483648";
//	int overflow = 1;
//	
//	printf("atoi : %d, overflow: %d", ft_atoi(arr, &overflow), overflow);
//}