/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:37:13 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/29 20:56:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

#include <criterion/criterion.h>
#include "inc/libft.h"
#include "inc/libft_types.h"
#include "inc/stringft.h"

Test(std_stdlib, atoi) {
	char	*str[] = {
		"42",
		"+42",
		"-42",
		"42   ",
		" \r\v\t\f\n42",
		"42lol",
		"lol42",
		"-0000000000000000000000000000000000000000000000000000000",
		"0000000000000000000000000000000000000000000000000000000000000000000000000001",
		"2147483647",
		"-2147483648",
		"-+5"
	};
	for (size_t i = 0; i < sizeof(str) / sizeof(*str); ++i) {
		int	exp = atoi(str[i]);
		int	got = ft_atoi(str[i]);
		cr_expect(exp == got, "For: %s\nExpected: %d\nGot: %d\n", str[i], exp, got);
	}
}

Test(std_stdlib, strtol) {
	struct {
		int		base;
		char	*nptr;
	}	elem[] = {
		{ 36, "1C8XUD6"},
		{ 36, "-1C8XuD6"},
		{ 2, "011101010101001011111" },
		{ 2, "-011101010101001011111" },
		{ 42, "LOL" },
		{ 24, "" },
		{ 24, "-" },
		{ 24, "   \n\tF69657i   abc    " },
		{ 24, "      " },
		{ 8, "00000000000000000000000000000000000000000000000000000000000000000000001" },
		{ 16, "-0x3287FF" },
		{ 24, "  -0x89fgh" },
		{ 10, "0x178" },
		{ 17, "0x3287ff" },
		{ 10, "9223372036854775807" },
		{ 10, "9223372036854775808" },
		{ 10, "-9223372036854775808" },
		{ 10, "-9223372036854775809" },
		{ 10, "32093897418498136473648314982741842648932164873219468297380173218369213"}
	};

	char	*exp_endptr = NULL;
	char	*got_endptr = NULL;
	int		exp_errno = 0;
	int		got_errno = 0;
	errno = 0;
	for (size_t i = 0; i < sizeof(elem) / sizeof(*elem); ++i) {
		long	exp = strtol(elem[i].nptr, &exp_endptr, elem[i].base);
		exp_errno = errno;
		errno = 0;
		long	got = ft_strtol(elem[i].nptr, &got_endptr, elem[i].base);
		got_errno = errno;
		errno = 0;

		cr_expect(exp == got && exp_endptr == got_endptr && exp_errno == got_errno, "For: \"%s\" base: %d\nExpected:\n\tret: %ld\n\tendptr: %p\n\terrno: %s\nGot:\n\tret: %ld\n\tendptr: %p\n\terrno: %s\n",
				elem[i].nptr, elem[i].base, exp, exp_endptr, strerror(exp_errno), got, got_endptr, strerror(got_errno));
	}
	unsigned long exp = strtoul("   +3901238", NULL, 0),
		got = ft_strtoul("    +3901238", NULL, 0);
	cr_expect(exp == got, "For: \"%s\", endptr: NULL, base: 0(10)\nExpected %zu, got %zu (if same it crashes)\n", "   +3901238", exp, got);
}

Test(std_stdlib, strtoul) {
	struct {
		int		base;
		char	*nptr;
	}	elem[] = {
		{ 36, "1C8XUD6"},
		{ 36, "-1C8XuD6"},
		{ 2, "011101010101001011111" },
		{ 2, "-011101010101001011111" },
		{ 42, "LOL" },
		{ 24, "" },
		{ 24, "-" },
		{ 24, "   \n\tF69657i   abc    " },
		{ 24, "      " },
		{ 8, "00000000000000000000000000000000000000000000000000000000000000000000001" },
		{ 16, "+0x3287FF" },
		{ 24, "  -0x89fgh" },
		{ 10, "0x178" },
		{ 17, "0x3287ff" },
		{ 10, "18446744073709551615" },
		{ 10, "18446744073709551615329838" },
		{ 10, "-9223372036854775808" },
		{ 10, "-9223372036854775809" },
		{ 10, "32093897418498136473648314982741842648932164873219468297380173218369213"}
	};

	char	*exp_endptr = NULL;
	char	*got_endptr = NULL;
	int		exp_errno = 0;
	int		got_errno = 0;
	errno = 0;
	for (size_t i = 0; i < sizeof(elem) / sizeof(*elem); ++i) {
		unsigned long	exp = strtoul(elem[i].nptr, &exp_endptr, elem[i].base);
		exp_errno = errno;
		errno = 0;
		unsigned long	got = ft_strtoul(elem[i].nptr, &got_endptr, elem[i].base);
		got_errno = errno;
		errno = 0;

		cr_expect(exp == got && exp_endptr == got_endptr && exp_errno == got_errno, "For: \"%s\" base: %d\nExpected:\n\tret: %zu\n\tendptr: %p\n\terrno: %s\nGot:\n\tret: %zu\n\tendptr: %p\n\terrno: %s\n",
				elem[i].nptr, elem[i].base, exp, exp_endptr, strerror(exp_errno), got, got_endptr, strerror(got_errno));
	}
	unsigned long exp = strtoul("   +3901238", NULL, 0),
		got = ft_strtoul("    +3901238", NULL, 0);
	cr_expect(exp == got, "For: \"%s\", endptr: NULL, base: 0(10)\nExpected %zu, got %zu (if same it crashes)\n", "   +3901238", exp, got);
}

Test(ft_string, string_new) {
	t_string	*s1 = string_new(42);
	t_string	*s2 = string_new(0);
	t_string	*s3 = string_new(1);

	cr_expect(s1 && s2 && s3, "Expected string_new not to return NULL");
	ft_free(s1);
	ft_free(s2);
	ft_free(s3);
}

#define size(x) (x + 32)

Test(ft_string, string_from) {
	t_string	*s1 = string_from("Hello");
	t_string	*s2 = string_from("world");
	t_string	*s3 = string_from("");

	cr_expect(!ft_strcmp(string_beg(s1), "Hello") && ft_blocksize(s1) == size(6), "\n%s\n%zu\n", string_beg(s1), ft_blocksize(s1));
	cr_expect(!ft_strcmp(string_beg(s2), "world") && ft_blocksize(s2) == size(6), "\n%s\n%zu\n", string_beg(s2), ft_blocksize(s2));
	cr_expect(!ft_strcmp(string_beg(s3), "") && ft_blocksize(s3) == size(1), "\n%s\n%zu\n", string_beg(s3), ft_blocksize(s3));
}
