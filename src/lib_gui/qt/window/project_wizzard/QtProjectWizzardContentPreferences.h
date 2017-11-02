#ifndef QT_PROJECT_WIZZARD_CONTENT_PREFERENCES_H
#define QT_PROJECT_WIZZARD_CONTENT_PREFERENCES_H

#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>

#include "qt/element/QtLocationPicker.h"
#include "qt/element/QtDirectoryListBox.h"
#include "qt/window/project_wizzard/QtProjectWizzardContent.h"
#include "utility/path_detector/CombinedPathDetector.h"

class QtFontPicker;
class QtTextEncodingPicker;

class QtProjectWizzardContentPreferences
	: public QtProjectWizzardContent
{
	Q_OBJECT

public:
	QtProjectWizzardContentPreferences(QtProjectWizzardWindow* window);
	~QtProjectWizzardContentPreferences();

	// QtProjectWizzardContent implementation
	virtual void populate(QGridLayout* layout, int& row) override;

	virtual void load() override;
	virtual void save() override;
	virtual bool check() override;

private slots:
	void colorSchemeChanged(int index);
	void javaPathDetectionClicked();
	void jreSystemLibraryPathsDetectionClicked();
	void mavenPathDetectionClicked();
	void loggingEnabledChanged();
	void indexerThreadsChanges(int index);

private:
	void addJavaPathDetection(QGridLayout* layout, int& row);
	void addJreSystemLibraryPathsDetection(QGridLayout* layout, int& row);
	void addMavenPathDetection(QGridLayout* layout, int& row);

	void addTitle(QString title, QGridLayout* layout, int& row);
	void addLabelAndWidget(
		QString label, QWidget* widget, QGridLayout* layout, int& row, Qt::Alignment widgetAlignment = Qt::Alignment());
	void addGap(QGridLayout* layout, int& row);

	QCheckBox* addCheckBox(QString label, QString text, QString helpText, QGridLayout* layout, int& row);
	QComboBox* addComboBox(QString label, QString helpText, QGridLayout* layout, int& row);
	QComboBox* addComboBox(QString label, int min, int max, QString helpText, QGridLayout* layout, int& row);
	QLineEdit* addLineEdit(QString label, QString helpText, QGridLayout* layout, int& row);

	QtFontPicker* m_fontFace;
	QComboBox* m_fontSize;
	QComboBox* m_tabWidth;
	QtTextEncodingPicker* m_textEncoding;

	QComboBox* m_colorSchemes;
	std::vector<FilePath> m_colorSchemePaths;
	int m_oldColorSchemeIndex;
	int m_newColorSchemeIndex;

	QCheckBox* m_useAnimations;
	QCheckBox* m_loggingEnabled;
	QCheckBox* m_verboseIndexerLoggingEnabled;

	QLineEdit* m_scrollSpeed;
	QCheckBox* m_graphZooming;

	QCheckBox* m_automaticUpdateCheck;

	QLineEdit* m_sourcetrailPort;
	QLineEdit* m_pluginPort;

	QComboBox* m_threads;
	QLabel* m_threadsInfoLabel;

	QCheckBox* m_multiProcessIndexing;

	std::shared_ptr<CombinedPathDetector> m_javaPathDetector;
	std::shared_ptr<CombinedPathDetector> m_jreSystemLibraryPathsDetector;
	std::shared_ptr<CombinedPathDetector> m_mavenPathDetector;

	QComboBox* m_javaPathDetectorBox;
	QComboBox* m_jreSystemLibraryPathsDetectorBox;
	QComboBox* m_mavenPathDetectorBox;
	QtLocationPicker* m_javaPath;
	QtDirectoryListBox* m_jreSystemLibraryPaths;
	QLineEdit* m_jvmMaximumMemory;
	QtLocationPicker* m_mavenPath;
};

#endif // QT_PROJECT_WIZZARD_CONTENT_PREFERENCES_H
