void 	ignore_fill(int **ignore, desc_lst main, int *cache)
{
	int i;

	i = 0;
	while (i < main->caches_amount)
	{
		if (cache[i] == 0)
			(*ignore)[i] = 0;
		else
			(*ignore)[i] = 1;
		i++;
	}
}

void	check_ignore(int *ignore, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ignore[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int 	find_best_cache(int num_c, int *request, int *ignore, int *cache_size)
{
	int i;
	int id;

	id = -1;
	i = 0;
	while (i < num_c)
	{
		if ((ignore[i] == 1 && cache_size[i] > 0) && ((id == -1) || request[i] > request[id]))
			id = i;
		i++;
	}
	return (id);
}

void	choose(desc_lst main, ep_lst ep, int **cache_size, int ***rez)
{
	int i;
	int id_cache;
	int *ignore;
	int id_cor_v;

	id_max_cache = 0;
	i = 0;
	ignore = (int*)malloc(sizeof(int) * caches_amount);
	ignore_fill(&ignore, main, ep->cache);
	while (check_ignore(ignore, main->caches_amount))
	{
		if ((id_cache = find_best_cache(main->caches_amount, ep->request, ignore, *cache_size)) == -1)
			break ;
		while ((id_cor_v = suitable_video_id(main, ep, *rez, (*cache_size)[id_cache])) != -1)
		{
			(*cache_size)[id_cache] -= main->vid_size[id_cor_v];
			(*rez)[id_cache][id_cor_v] = 1;
		}
		ignore[id_cache] = 0;
	}
}