/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:18 by rdelicad          #+#    #+#             */
/*   Updated: 2024/01/19 13:11:04 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// 000LIBFT1
int		ft_strlen(char *str);
char	*ft_strnstr(char *b, char *l, size_t len);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *lsh, const char *rhs, int count);
int		ft_atoi(const char *str);

// 001SPLIT
char	**ft_split(char *s, char c);

// 002LISTS
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstprint(t_list *lst);

// 100CHECK
int		ft_check_parameters(t_data *d);
void	ft_check_characters(t_data *d);
int		ft_allow_chars(char *s, t_data *d);

// 101-1CHECKLIMITS
void	ft_duplicate_map(t_data *d);
void	ft_flood_fill(int x, int y, t_data *d);
void	ft_locate_player(t_data *d);
int		ft_check_inner_walls(t_data *d);
int		ft_o_num(char *str);

// 101-2CHECKLIMITS
int		ft_check_around(t_data *d, int x, int y);
int		ft_check_outer_walls(t_data *d);
void	ft_compare_maps(t_data *d);
void	ft_check_outer_chars(t_data *d);
void	ft_fill_islands(t_data *d);

// 101-3CHECKLIMITS
void	ft_check_limits(t_data *d);

// 102-1CHECKCONTENTFILE
void	ft_my_strjoin_operations(t_my_strjoin_data *d);
char	*ft_my_strjoin(char **str1, char **str2);
char	*ft_get_all_content(t_data *d);

// 102-2CHECKCONTENTFILE
void	ft_check_init_row(char *c_w_space, char *path, t_data *d);

// 102-3CHECKCONTENTFILE
void	ft_check_start_row(char *row_n_content, t_data *d);
void	ft_add_row_list(t_data *d, char *str);
int		ft_check_data_file(t_data *d);
char	**ft_create_map(t_data *d);
void	ft_check_content_file(t_data *d);

// 110INITIALIZE
void	ft_number_rows(t_data *d);
void	ft_initialize_map(t_data *d, char **map);

// 120ERRORMESSAGES
void	ft_error_messages(int message);

// 200GNL
char	*ft_join_free(char *buffer, char *str);
char	*ft_get_next_line(int fd);

// 210GNLUTILS
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen_n(const char *s);
char	*ft_strchr(const char *s, int c);

// 999FREE
void	ft_free_all(t_data *d);
void	ft_free_matrix(char **matrix);
