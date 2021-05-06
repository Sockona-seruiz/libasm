#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

typedef struct	s_list
{
	void 		*data;
	struct		s_list *next;
}				t_list;

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *source);
char	*ft_strdup(const char	*source);
size_t	ft_write(int fd, const void *buf, size_t count);
size_t	ft_read(int fd, const void *buf, size_t count);
int		ft_list_size(t_list *begin_list);

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	if ((result = malloc(sizeof(t_list *))) == 0)
		return (0);
	result->data = content;
	result->next = 0;
	return (result);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *buffer;

	if (!alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	buffer = *alst;
	while (buffer->next != 0)
		buffer = buffer->next;
	buffer->next = new;
}


int	main(void)
{
	int64_t	len;
	int64_t	cmp;
	size_t	ret;
	int		i;
	char	*dest;
	char	*dest_2;
	char	*str_dup;
	char	source[15] = "wesh la street";
	t_list	*list;
	t_list	*list_2;

	dest = malloc(sizeof(char) * 15);
	dest_2 = malloc(sizeof(char) * 15);



	printf("=================ft_strlen=====================");

	len = ft_strlen("test");
	printf("\nft_strlen = %lld\n", len);
	len = strlen("test");
	printf("strlen    = %lld\n", len);

	len = ft_strlen("testlong");
	printf("\nft_strlen = %lld\n", len);
	len = strlen("testlong");
	printf("strlen    = %lld\n", len);

	len = ft_strlen("testlonglong");
	printf("\nft_strlen = %lld\n", len);
	len = strlen("testlonglong");
	printf("strlen    = %lld\n", len);;

	len = ft_strlen("te");
	printf("\nft_strlen = %lld\n", len);
	len = strlen("te");
	printf("strlen    = %lld\n", len);

	len = ft_strlen("");
	printf("\nft_strlen = %lld\n", len);
	len = strlen("");
	printf("strlen    = %lld\n", len);

	printf("=================ft_strcmp=====================");




	printf("\nTripouille START\n");
	cmp = ft_strcmp("", "");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("", "");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "Tripouille");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "Tripouille");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "tripouille");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "tripouille");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "TriPouille");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "TriPouille");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "TripouillE");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "TripouillE");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "TripouilleX");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "TripouilleX");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("Tripouille", "Tripouill");
	printf ("\nft_strcmp = %lld\n", cmp);
	cmp = strcmp("Tripouille", "Tripouill");
	printf ("strcmp    = %lld\n", cmp);

	printf("\nTripouille END\n");




	cmp = ft_strcmp("test wesh la street", "test wesh le man");
	printf ("\nft_strcmp = %lld\n", cmp);

	cmp = strcmp("test wesh la street", "test wesh le man");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("test wesh la street", "test wesh la street");
	printf ("\nft_strcmp = %lld\n", cmp);

	cmp = strcmp("test wesh la street", "test wesh la street");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("test wesh le man", "test wesh la street");
	printf ("\nft_strcmp = %lld\n", cmp);

	cmp = strcmp("test wesh le man", "test wesh la street");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("", "test wesh la street");
	printf ("\nft_strcmp = %lld\n", cmp);

	cmp = strcmp("", "test wesh la street");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("essgfesd", "");
	printf ("\nft_strcmp = %lld\n", cmp);

	cmp = strcmp("essgfesd", "");
	printf ("strcmp    = %lld\n", cmp);

	cmp = ft_strcmp("", "");
	printf ("\nstrcmp    = %lld\n", cmp);

	cmp = strcmp("", "");
	printf ("strcmp    = %lld\n", cmp);

	printf("=================ft_strcpy=====================");

	dest = ft_strcpy(dest, source);
	printf("\nft_strcpy = %s\n", dest);
	printf("source    = %s\n", source);

	dest_2 = strcpy(dest_2, source);
	printf("strcpy    = %s\n", dest_2);
	printf("source    = %s\n", source);

	dest = ft_strcpy(dest, "");
	printf("\nft_strcpy = %s\n", dest);
	printf("source    = %s\n", "");

	dest_2 = strcpy(dest_2, "");
	printf("strcpy    = %s\n", dest_2);
	printf("source    = %s\n", "");

	printf("=================ft_strdup=====================");

	str_dup = ft_strdup("This str will be copied");
	printf("\nft_strdup = %s\n", str_dup);
	free(str_dup);

	str_dup = ft_strdup("");
	printf("\nft_strdup = %s\n", str_dup);
	free(str_dup);

	str_dup = ft_strdup("Test alo Wfeds ? ! Wfsdg end");
	printf("\nft_strdup = %s\n", str_dup);
	free(str_dup);

	printf("=================ft_write======================\n");

	ret = ft_write(-1, source, ft_strlen(source));
	printf("\n%s\n", strerror(errno));
	printf("\nft_write = %zu\n", ret);

	ret = write(-1, source, strlen(source));
	printf("\n%s\n", strerror(errno));
	printf("\nwrite    = %zu\n", ret);

	printf("\n\n");

	ret = ft_write(1, source, ft_strlen(source));
	printf("\nft_write = %zu\n", ret);

	ret = write(1, source, strlen(source));
	printf("\nwrite    = %zu\n", ret);

	printf("=================ft_read=======================\n");
	char	buff[20];

	ret = read(0, buff, 20);
	printf("read    = %s\n", buff);

	ret = ft_read(0, buff, 20);
	printf("ft_read = %s\n", buff);

	ret = ft_read(-1, source, ft_strlen(source));
	printf("\n%s\n", strerror(errno));

	ret = read(-1, source, strlen(source));
	printf("\n%s\n", strerror(errno));

/*
	printf("=================ft_lstsize====================\n");
	list = ft_lstnew("test");

	i = 0;
	while (i < 12)
	{
		ft_lstadd_back(&list, ft_lstnew("wesh"));
		i++;
	}
	i = ft_list_size(list);
	printf("list size = %d\n", i);

	list_2 = ft_lstnew("test");

	i = 0;
	while (i < 41)
	{
		ft_lstadd_back(&list_2, ft_lstnew("wesh"));
		i++;
	}
	i = ft_list_size(list_2);
	printf("list_2 sze= %d\n", i);
*/
	return (0);
}
