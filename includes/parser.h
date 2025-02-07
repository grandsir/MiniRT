/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:23:28 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:31:09 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minirt.h"

typedef enum s_tokens	t_tokens;
typedef struct s_global	t_global;
typedef struct s_camera	t_camera;

t_global				parse_input(char *file);
t_tokens				return_type(char *s);
t_ambient				*ambient_empty(void);
t_ambient				*ambient_assign(char *line);
t_camera				*cam_assign(char *line);
t_point_light			*point_light_empty(void);
t_point_light			*point_light_assign(char *line);
char					*read_float(char *line, float *o, float min, float max);
char					*read_vector(char *line, t_vector *o, float min,
							float max);
char					*skip_spaces(char *s);
char					*find_next_chunk(char *line);
char					*line_to_chunk(char *line);
int						check_file_type(char *input);
int						*object_assign(char *line, t_tokens t, t_object **objs);
int						coordinate_to_vector(char *s, t_vector *vec4);

#endif