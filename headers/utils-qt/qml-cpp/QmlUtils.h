#pragma once
#include <QObject>
#include <QList>
#include <QStringList>
#include <utils-cpp/pimpl.h>

class QmlUtils : public QObject
{
    Q_OBJECT
public:
    static QmlUtils& instance();
    static void registerTypes();

#ifdef WIN32
    Q_PROPERTY(bool displayRequired READ displayRequired WRITE setDisplayRequired NOTIFY displayRequiredChanged)
    Q_PROPERTY(bool systemRequired READ systemRequired WRITE setSystemRequired NOTIFY systemRequiredChanged)
#endif
    Q_PROPERTY(int keyModifiers READ keyModifiers /*WRITE setKeyModifiers*/ NOTIFY keyModifiersChanged)

    bool eventFilter(QObject* watched, QEvent* event) override;

    Q_INVOKABLE bool isImage(const QString& fileName) const;
    Q_INVOKABLE QString normalizePath(const QString& str) const;
    Q_INVOKABLE QString normalizePathUrl(const QString& str) const;
    Q_INVOKABLE int bound(int min, int value, int max) const;
    Q_INVOKABLE QString realFileName(const QString& str) const;
    Q_INVOKABLE QString realFileNameUrl(const QString& str) const;
    Q_INVOKABLE QString extractFileName(const QString& filePath) const;
    Q_INVOKABLE QString pathUrlFromLocalFile(const QString& localFile) const;
    Q_INVOKABLE bool isNull(const QVariant& value) const;
    Q_INVOKABLE bool isFloat(const QVariant& value) const;
    Q_INVOKABLE bool isInteger(const QVariant& value) const;
    Q_INVOKABLE bool isNumber(const QVariant& value) const;
    Q_INVOKABLE bool compare(const QVariant& value1, const QVariant& value2) const;
    Q_INVOKABLE QString extractByRegex(const QString& source, const QString& pattern) const;
    Q_INVOKABLE QStringList extractByRegexGroups(const QString& source, const QString& pattern, const QList<int>& groups) const;
    Q_INVOKABLE QString toHex(int value, bool upperCase = true, int width = 0) const;
    Q_INVOKABLE QString sizeConv(int size, int limit = 1000, int decimals = 1) const;
    Q_INVOKABLE bool urlFileExists(const QUrl& url) const;
    Q_INVOKABLE bool localFileExists(const QString& fileName) const;

    Q_INVOKABLE void showWindow(QObject* win);
    Q_INVOKABLE void minimizeWindow(QObject* win);

// --- Properties support ---
public:
#ifdef WIN32
    bool displayRequired() const;
    bool systemRequired() const;
#endif
    int keyModifiers() const;

public slots:
#ifdef WIN32
    void setDisplayRequired(bool value);
    void setSystemRequired(bool value);
#endif

private slots:
    void setKeyModifiers(int value);

signals:
#ifdef WIN32
    void displayRequiredChanged(bool displayRequired);
    void systemRequiredChanged(bool systemRequired);
#endif
    void keyModifiersChanged(int keyModifiers);
// --- ---

private:
    QmlUtils();
    ~QmlUtils() override;

    void updateExecutionState();

private:
    DECLARE_PIMPL
};
