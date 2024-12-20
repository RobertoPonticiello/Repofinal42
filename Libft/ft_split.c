#include "libft.h"


static int	count_words(char const *s, char c)
{
	int count;
	int in_word;

	if (!s)
		return (-1);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*copy_word(char const *s, int start, int len)
{
	char *word;
	int i;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, int words)
{
	int i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**fill_result(char **result, char const *s, char c, int words)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		len = word_length(s + i, c);
		result[j] = copy_word(s, i, len);
		if (!result[j])
		{
			free_all(result, j);
			return (NULL);
		}
		i += len;
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char **result;
	int words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (fill_result(result, s, c, words));
}
