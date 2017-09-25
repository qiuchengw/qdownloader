#pragma once

#include <QObject>
#include <QNetworkReply>

namespace qdownloader 
{

	class Downloader : public QObject
	{
		Q_OBJECT

	public:
		Downloader(QObject *parent = nullptr);
		~Downloader();

		void setParalledDownload(int n) {
			parell_download_ = n;
		}

		void setDownloadPath(const QString& path) {
			save_dir_ = path;
		}

		const QStringList& setItems(const QStringList& items);

		int index(const QString& url)const {
			return items_.indexOf(url);
		}

		void start();
		void stop();

		bool isAllDone()const {
			return done_ >= items_.count();
		}

	protected:
		QString download(const QString& url);

	signals:
		void downloadEvent(int evt, QUrl, int progress, QString error);
		void finished(int);

		protected slots:
		void onDownload(int evt, QUrl, int progress, QNetworkReply::NetworkError);

	private:
		// ���浽��·��
		QString save_dir_;
		// ������Ҫ���ص�����
		QStringList items_;

		// ��ǰ���һ�����ص�λ��
		int idx_ = 0;
		// ��ǰ��ȷ���������/���ش����ͼƬ����
		int done_ = 0;
		// ͬʱ���صĸ���
		int parell_download_ = 5;

		bool started_ = false;
	};

}
