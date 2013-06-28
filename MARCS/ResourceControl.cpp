#include "ResourceControl.h"

QString ResourceControl::getImage(QString p_pName)
{
	if (m_pResources.isNull())
	{
		loadResource();
	}

	QDomElement pRoot = m_pResources.documentElement();
	QDomElement pItem;
	QDomNode pNode = pRoot.firstChild();
	QDomNodeList pNodeArray;

	while (!pNode.isNull())
	{
		pItem = pNode.toElement();

		if (pItem.tagName() == "img")
		{
			if (pItem.attribute("name") == p_pName)
			{
				return pItem.attribute("path");
			}
		}
		pNode = pNode.nextSibling();
	}

	return QString();
}

QString ResourceControl::getSound(QString p_pName)
{
	if (m_pResources.isNull())
	{
		loadResource();
	}

	QDomElement pRoot = m_pResources.documentElement();
	QDomElement pItem;
	QDomNode pNode = pRoot.firstChild();
	QDomNodeList pNodeArray;

	while (!pNode.isNull())
	{
		pItem = pNode.toElement();

		if (pItem.tagName() == "snd")
		{
			if (pItem.attribute("name") == p_pName)
			{
				return pItem.attribute("path");
			}
		}
		pNode = pNode.nextSibling();
	}

	return QString();
}

QString ResourceControl::getText(QString p_pName)
{
	if (m_pResources.isNull())
	{
		loadResource();
	}

	QDomElement pRoot = m_pResources.documentElement();
	QDomElement pItem;
	QDomNode pNode = pRoot.firstChild();
	QDomNodeList pNodeArray;

	while (!pNode.isNull())
	{
		pItem = pNode.toElement();

		if (pItem.tagName() == "txt")
		{
			if (pItem.attribute("name") == p_pName)
			{
				return pItem.attribute("text");
			}
		}
		pNode = pNode.nextSibling();
	}

	return QString();
} 

void ResourceControl::loadResource()
{
	QFile pFile("resources.xml");

	if (!pFile.open(QIODevice::ReadOnly))
	{
		return;
	}

	if (!m_pResources.setContent(&pFile))
	{
		pFile.close();
		return;
	}
	pFile.close();
}