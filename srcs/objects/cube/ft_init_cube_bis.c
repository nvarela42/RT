/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:06:02 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/13 19:05:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		*ft_add(t_vects *vect, int m_id, t_scene *scn)
{
	t_objects	*new_tri;

	new_tri = (t_objects*)ft_create_object(scn);
	new_tri->pos_edge1 = (t_vector){vect->a.x, vect->a.y, vect->a.z};
	new_tri->pos_edge2 = (t_vector){vect->b.x, vect->b.y, vect->b.z};
	new_tri->pos_edge3 = (t_vector){vect->c.x, vect->c.y, vect->c.z};
	new_tri->material_id = m_id;
	new_tri->type = 5;
	return (new_tri);
}

static void		ft_init_tab_vect(t_vects *vect, t_objects *cube)
{
	vect[0] = (t_vects){cube->edge_a, cube->edge_b, cube->edge_c};
	vect[1] = (t_vects){cube->edge_c, cube->edge_b, cube->edge_d};
	vect[2] = (t_vects){cube->edge_b, cube->edge_e, cube->edge_d};
	vect[3] = (t_vects){cube->edge_d, cube->edge_e, cube->edge_f};
	vect[4] = (t_vects){cube->edge_h, cube->edge_e, cube->edge_f};
	vect[5] = (t_vects){cube->edge_h, cube->edge_e, cube->edge_g};
	vect[6] = (t_vects){cube->edge_h, cube->edge_g, cube->edge_c};
	vect[7] = (t_vects){cube->edge_c, cube->edge_g, cube->edge_a};
	vect[8] = (t_vects){cube->edge_c, cube->edge_d, cube->edge_h};
	vect[9] = (t_vects){cube->edge_h, cube->edge_d, cube->edge_f};
	vect[10] = (t_vects){cube->edge_a, cube->edge_e, cube->edge_g};
	vect[11] = (t_vects){cube->edge_a, cube->edge_e, cube->edge_b};
}

void			ft_add_edges(t_objects *cube, t_scene *scn)
{
	t_objects	*tri_tab[12];
	t_vects		vect_tab[12];

	ft_init_tab_vect(vect_tab, cube);
	tri_tab[0] = ft_add(&vect_tab[0], cube->material_id, scn);
	tri_tab[1] = ft_add(&vect_tab[1], cube->material_id, scn);
	tri_tab[2] = ft_add(&vect_tab[2], cube->material_id1, scn);
	tri_tab[3] = ft_add(&vect_tab[3], cube->material_id1, scn);
	tri_tab[4] = ft_add(&vect_tab[4], cube->material_id2, scn);
	tri_tab[5] = ft_add(&vect_tab[5], cube->material_id2, scn);
	tri_tab[6] = ft_add(&vect_tab[6], cube->material_id3, scn);
	tri_tab[7] = ft_add(&vect_tab[7], cube->material_id3, scn);
	tri_tab[8] = ft_add(&vect_tab[8], cube->material_id4, scn);
	tri_tab[9] = ft_add(&vect_tab[9], cube->material_id4, scn);
	tri_tab[10] = ft_add(&vect_tab[10], cube->material_id5, scn);
	tri_tab[11] = ft_add(&vect_tab[11], cube->material_id5, scn);
}
