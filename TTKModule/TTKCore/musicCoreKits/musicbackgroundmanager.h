#ifndef MUSICBACKGROUNDMANAGER_H
#define MUSICBACKGROUNDMANAGER_H

/***************************************************************************
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2024 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "musicobject.h"
#include "ttksingleton.h"

/*! @brief The class of the manager of dealing with artist pictures.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT MusicBackgroundManager : public QObject
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicBackgroundManager)
public:
    /*!
     * Set current artist name.
     */
    void setArtistName(const QString &name);
    /*!
     * Get current artist name.
     */
    QString artistName() const;

    /*!
     * Get artist image current index.
     */
    inline int currentIndex() const { return m_currentIndex; }
    /*!
     * Set artist image current index.
     */
    inline void setCurrentIndex(int index) { m_currentIndex = index; }
    /*!
     * Get artist image count.
     */
    inline int count() const { return m_images.count(); }
    /*!
     * Get artist image count is 0.
     */
    inline bool isEmpty() const { return m_images.isEmpty(); }

    /*!
     * Set artist image current index + 1.
     */
    void imageNext();
    /*!
     * Set artist image current index - 1.
     */
    void imagePrevious();

    /*!
     * Get artist image path.
     */
    QString artistImagePath();
    /*!
     * Get artist image path by default.
     */
    QString artistImageDefaultPath() const;

    /*!
     * Update artist image list.
     */
    void updateArtistImageList();
    /*!
     * Get artist image path list.
     */
    QStringList artistImageList() const;
    /*!
     * Set artist image path by given path list.
     */
    void setArtistImageList(const QStringList &list);
    /*!
     * Set user select current index.
     */
    void setSelectArtistIndex(int index);

    /*!
     * Add observer.
     */
    void addObserver(QObject *object);
    /*!
     * Remove observer.
     */
    void removeObserver(QObject *object);

    /*!
     * Set artist background picture by path.
     */
    void setBackgroundUrl(const QString &path);
    /*!
     * Get artist background picture path.
     */
    QString backgroundUrl() const;

    /*!
     * Get artist background picture path.
     */
    void backgroundUrlChanged();

Q_SIGNALS:
    /*!
     * New artist has been set.
     */
    void artistChanged();
    /*!
     * Background image changed.
     */
    void backgroundChanged();
    /*!
     * User selected index changed.
     */
    void selectIndexChanged();

private:
    /*!
     * Object constructor.
     */
    MusicBackgroundManager();

    int m_currentIndex;
    QStringList m_images;
    QObjectList m_observer;
    QString m_currentArtistName, m_background;

    TTK_DECLARE_SINGLETON_CLASS(MusicBackgroundManager)

};

#define G_BACKGROUND_PTR makeMusicBackgroundManager()
TTK_MODULE_EXPORT MusicBackgroundManager* makeMusicBackgroundManager();

#endif // MUSICBACKGROUNDMANAGER_H
