/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_schema.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:29:58 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/08 22:03:40 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int							ft_validate_schema(xmlDocPtr doc, const char *xsd)
{
	int						ret;
	xmlSchemaPtr			schema;
	xmlSchemaValidCtxtPtr	vctxt;
	xmlSchemaParserCtxtPtr	pctxt;

	if ((pctxt = xmlSchemaNewParserCtxt(xsd)) == NULL)
		return (-1);
	schema = xmlSchemaParse(pctxt);
	xmlSchemaFreeParserCtxt(pctxt);
	if (schema == NULL)
		return (-1);
	if ((vctxt = xmlSchemaNewValidCtxt(schema)) == NULL)
	{
		xmlSchemaFree(schema);
		return (-1);
	}
	ret = xmlSchemaValidateDoc(vctxt, doc);
	xmlSchemaFree(schema);
	xmlSchemaFreeValidCtxt(vctxt);
	return (ret);
}
