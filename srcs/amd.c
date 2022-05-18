#include "cub3D.h"

int get_map_idx(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        if (map[i][0] == '1')
        {
            return i;
        }
        i++;
    }
    return (-1);
}

void ft_free(void *f)
{
    if (f != NULL)
    {
        free(f);
    }
}

void ft_free_all(void **f)
{
    int i = 0;
    while (f[i] != NULL)
    {
        free(f[i]);
        i++;
    }
    ft_free(f);
}

t_color empty_color()
{
    t_color t = {.r = -1, .g = -1, .b = -1};
    return t;
}

int is_empty_color(t_color color)
{
    return color.r == -1 && color.g == -1 && color.b == -1;
}

int is_valid_map_char(char c)
{
    return c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ';
}

int is_valid_map(char **s, int start)
{
    int i;
    int j;
    int len;
    len = 0;
    i = start;
    j = 0;
    while (s[i] != NULL)
    {
        j = 0;
        while (s[i][j] != '\0')
        {
            if (i == start || i == count(s) - 1)
            {
                if (s[i][j] != '1' && s[i][j] != ' ')
                    return (0);
            }
            else
            {
                len = ft_strlen(s[i]);
                if (s[i][0] != '1' && s[i][len - 1] != '1')
                    return (0);
                if (!is_valid_map_char(s[i][j]))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

char **extract_map(char **s, int line_idx)
{
    char **map;
    int i;
    i = 0;
    map = malloc(sizeof(char *) * (count(s) - line_idx));
    if (map == NULL)
        return NULL;
    while (s[line_idx] != NULL)
    {
        map[i++] = s[line_idx++];
    }
    map[i] = NULL;
    return map;
}

t_game *parse(char *file)
{
    int fd;
    char **map;
    int line_number = 0;
    int map_idx = 0;
    t_game *game = NULL;
    char **tokens;
    int error = 0;

    fd = open_file(file);
    if (fd == -1)
        return NULL;
    game = new_game();
    map = read_file(fd);
    map_idx = get_map_idx(map);

    // parse metadata
    while (map[line_number] != NULL)
    {
        if (line_number != map_idx)
        {
            tokens = ft_split(map[line_number], ' ');
            if (count(tokens) < 2)
            {
                error = 1;
                printf("Error\n %s\n", map[line_number]);
                break;
            }
            // check texture
            if (is_ea_texture(tokens))
            {
                if (game->texture_ea != NULL)
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->texture_ea = tokens[1];
                line_number++;
                continue;
            }
            if (is_so_texture(tokens))
            {
                if (game->texture_so != NULL)
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->texture_so = tokens[1];
                line_number++;
                continue;
            }
            if (is_we_texture(tokens))
            {
                if (game->texture_we != NULL)
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->texture_we = tokens[1];
                line_number++;
                continue;
            }
            if (is_no_texture(tokens))
            {
                if (game->texture_no != NULL)
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->texture_no = tokens[1];
                line_number++;
                continue;
            }
            // check floor;
            if (!is_empty_color(is_floor(tokens)))
            {
                if (!is_empty_color(game->floor))
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->floor = is_floor(tokens);
                line_number++;
                continue;
            }
            // check celeing
            if (!is_empty_color(is_ceiling(tokens)))
            {
                if (!is_empty_color(game->celeing))
                {
                    error = 1;
                    printf("Error\nDuplicate %s\n", map[line_number]);
                    break;
                }
                game->celeing = is_ceiling(tokens);
                line_number++;
                continue;
            }
            else
            {
                error = 1;
                printf("Error\n%s", map[line_number]);
                break;
            }
            // error
        }
        else
        {
            if (!is_valid_map(map, line_number))
            {
                error = 1;
                printf("Error\n%s", "Invalid map\n");
                break;
            }
            game->map = extract_map(map, map_idx);
            if (game->map == NULL)
            {
                error = 1;
                printf("Error\n");
                break;
            }
        }
        line_number++;
    }
    // if (error)
    // {
    //     ft_free(game);
    //     ft_free_all(tokens);
    //     ft_free_all(map);
    //     return NULL;
    // }

    // ft_free_all(map);
    return (game);
    // parse map
}


