#ifndef HASH_H
# define HASH_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/printf_functions/includes/header.h"

typedef struct      s_lst
{
    int             vid_amount;
    int             ep_amount;
    int             requests;
    int             caches_amount;
    int             cache_size;
    int             *vid_size;
}                   desc_lst;

typedef struct      s_ep
{
    int             *requests; //количество запросов с соответствующего эндпоинта
    int             *cache;
}                   ep_lst;

typedef struct      s_vid
{
    int             *id;
    int             *mem;
}                   cache_lst;

#endif