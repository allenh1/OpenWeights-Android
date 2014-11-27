#include <QDate>
/**
 * @brief LogItem wrapper
 *
 * This struct contains a log item and its basic properties.
 * @see logComparator
 */
struct logItem
{
    int m_bicep;
    int m_tricep;
    int m_chest;

    QString asString;
    QDate m_date;
};

/**
 * Allows for comparison of the objects in the array.
 * May not be completely necessary for anything ever,
 * but function objects are kinda neat. :P
 */
struct Comparator {
    bool operator () (const logItem & l1, const logItem & l2) const {
        return l1.m_date < l2.m_date;
    }
};
