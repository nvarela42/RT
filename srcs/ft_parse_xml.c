/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_xml.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:50:09 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/13 19:16:16 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			ft_search_xml(t_rt *rt, char *name)
{
	int				i;

	i = 0;
	while (rt->object[i] != NULL)
	{
		if (!ft_strcmp(rt->object[i], name))
			return (i);
		i++;
	}
	return (-1);
}

static void			ft_run_xml_parse(t_rt *rt, xmlNodePtr node, t_scene *scn)
{
	xmlNodePtr		n;
	void			*obj;
	int				i;

	n = node;
	while (n)
	{
		i = ft_search_xml(rt, (char *)n->name);
		if (i == -1)
			ft_run_xml_parse(rt, n->children, scn);
		else
		{
			rt->progress.current++;
			ft_print_xml_progression(rt, (char *)n->name);
			obj = (*rt->object_create[i])(scn);
			(*rt->object_init[i])(obj, n, scn);
		}
		n = n->next;
	}
}

static void			ft_count_xml_node(t_rt *rt, xmlNodePtr node)
{
	xmlNodePtr		n;
	int				i;

	n = node;
	while (n)
	{
		i = ft_search_xml(rt, (char *)n->name);
		if (i == -1)
			ft_count_xml_node(rt, n->children);
		else
			rt->progress.max++;
		n = n->next;
	}
}

static void			ft_parse_xml_bis(t_rt *rt, xmlDocPtr doc, xmlNodePtr root)
{
	t_scene			*scn;

	ft_create_scene(rt, doc);
	ft_count_xml_node(rt, root);
	ft_putendl_fd("####################", 1);
	ft_putendl_fd("# Parsing xml node #", 1);
	ft_putendl_fd("####################", 1);
	scn = ft_get_last_scene(rt->scenes);
	ft_run_xml_parse(rt, root, scn);
}

int					ft_parse_xml(t_rt *rt, char *filename)
{
	xmlDocPtr		doc;
	xmlNodePtr		root;

	xmlKeepBlanksDefault(0);
	doc = xmlParseFile(filename);
	if (doc == NULL)
		return (ft_print_error_xml(rt, "Invalid XML file"));
	root = xmlDocGetRootElement(doc);
	if (root == NULL)
	{
		xmlFreeDoc(doc);
		return (ft_print_error_xml(rt, "Empty XML file"));
	}
	if (ft_validate_schema(doc, ft_glob()->xsdfile) != 0)
	{
		xmlFreeDoc(doc);
		return (ft_print_error_xml(rt, "Xml file can't be valid with XSD"));
	}
	ft_parse_xml_bis(rt, doc, root);
	xmlFreeDoc(doc);
	return (0);
}
