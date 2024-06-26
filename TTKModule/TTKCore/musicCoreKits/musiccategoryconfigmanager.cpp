#include "musiccategoryconfigmanager.h"
#include "musicobject.h"

MusicCategoryConfigManager::MusicCategoryConfigManager(const QString &key)
    : TTKAbstractXml(),
      m_type(key)
{

}

bool MusicCategoryConfigManager::fromFile(Category type)
{
    QString v;
    switch(type)
    {
        case Category::PlayList: v = RESOURCE_DIR_FULL + "playlist"; break;
        case Category::TopList: v = RESOURCE_DIR_FULL + "toplist"; break;
        case Category::ArtistList: v = RESOURCE_DIR_FULL + "artistlist"; break;
        case Category::MovieList: v = RESOURCE_DIR_FULL + "movielist"; break;
        default: break;
    }

    return TTKAbstractXml::fromFile(v);
}

bool MusicCategoryConfigManager::readBuffer(MusicResultsCategoryList &items)
{
    const QDomNodeList &nodes = m_document->elementsByTagName(m_type);
    for(int i = 0; i < nodes.count(); ++i)
    {
        const QDomNodeList &tagNodes = nodes.item(i).childNodes();
        for(int j = 0; j < tagNodes.count(); ++j)
        {
            MusicResultsCategory category;
            const QDomNode &tagNode = tagNodes.item(j);
            category.m_category = tagNode.toElement().attribute("value");

            if(category.m_category.isEmpty())
            {
                continue;
            }

            const QDomNodeList &typeNodes = tagNode.childNodes();
            for(int k = 0; k < typeNodes.count(); ++k)
            {
                const QDomElement &element = typeNodes.item(k).toElement();

                MusicResultsCategoryItem item;
                item.m_key = element.attribute("key");
                item.m_value = element.attribute("value");
                category.m_items.append(item);
            }

            items.append(category);
        }
    }

    return true;
}
