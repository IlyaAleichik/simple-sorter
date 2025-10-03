#define PATH "/path"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

using namespace std;
namespace fs = std::filesystem;

vector<string> images = { "jpg", "jpeg", "png", "gif", "bmp", "svg", "webp", "tiff", "heic" };
vector<string> audio = { "mp3", "wav", "flac", "aac", "ogg", "m4a", "wma" };
vector<string> videos = { "mp4", "mov", "avi", "mkv", "flv", "webm", "wmv", "mpeg" };
vector<string> documents = { "pdf", "doc", "docx", "xls", "xlsx", "ppt", "pptx", "txt", "rtf" };
vector<string> archives = { "zip", "rar", "7z", "tar", "gz", "iso" };
vector<string> programs = { "exe", "msi", "dmg", "pkg", "deb", "apk" };
vector<string> scripts = { "py", "js", "php", "sh", "bat", "ps1", "cpp", "h", "java" };
vector<string> torrents = { "torrent" };
vector<string> design = { "psd", "ai", "fig", "xd", "sketch" };
vector<string> database = { "sql", "db", "sqlite", "csv", "json" };
vector<string> models = { "stl", "obj", "fbx", "blend", "3ds" };

//void sortFiles() {
//
//    int mode;
//    cout << "Select sort mode:\n1 - Type fiels\n2 - Extensions files\n > [Default 1]: ";
//    cin >> mode;
//    if (cin.fail()) {
//        mode = 1;
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    int copy;
//    cout << "Copy or transfer file?:\n1 - Copy\n2 - Move\n > [Default 1]: ";
//    cin >> copy;
//    if (cin.fail()) {
//        copy = 1;
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }
//
//    string dir = "C:/Users/ilya/Desktop/sorter/";
//    string current_file = fs::path("script.cpp").filename().string();  // Например: "script.cpp"
//
//    for (const auto& file : fs::directory_iterator(PATH)) {
//        if (fs::is_regular_file(file) && file.path().filename() != current_file) {
//            string extension = file.path().extension().string().substr(1); // Remove the dot
//            string target_dir;
//
//            if (mode == 2) {
//                target_dir = dir + "." + extension;
//            }
//            else {
//                if (find(images.begin(), images.end(), extension) != images.end()) {
//                    target_dir = dir + "images";
//                }
//                else if (find(audio.begin(), audio.end(), extension) != audio.end()) {
//                    target_dir = dir + "audio";
//                }
//                else if (find(videos.begin(), videos.end(), extension) != videos.end()) {
//                    target_dir = dir + "videos";
//                }
//                else if (find(documents.begin(), documents.end(), extension) != documents.end()) {
//                    target_dir = dir + "documents";
//                }
//                else if (find(archives.begin(), archives.end(), extension) != archives.end()) {
//                    target_dir = dir + "archives";
//                }
//                else if (find(programs.begin(), programs.end(), extension) != programs.end()) {
//                    target_dir = dir + "programs";
//                }
//                else if (find(scripts.begin(), scripts.end(), extension) != scripts.end()) {
//                    target_dir = dir + "scripts";
//                }
//                else if (find(torrents.begin(), torrents.end(), extension) != torrents.end()) {
//                    target_dir = dir + "torrents";
//                }
//                else if (find(design.begin(), design.end(), extension) != design.end()) {
//                    target_dir = dir + "design";
//                }
//                else if (find(database.begin(), database.end(), extension) != database.end()) {
//                    target_dir = dir + "database";
//                }
//                else if (find(models.begin(), models.end(), extension) != models.end()) {
//                    target_dir = dir + "models";
//                }
//                else {
//                    target_dir = dir + "other";
//                }
//            }
//
//            fs::create_directories(target_dir);
//            if (copy == 2) {
//                fs::rename(file.path(), target_dir + "/" + file.path().filename().string());
//            }
//            else {
//                fs::copy(file.path(), target_dir + "/" + file.path().filename().string(), fs::copy_options::overwrite_existing);
//            }
//        }
//    }
//
//    cout << "Сортировка завершена. Нажмите любую клавишу для закрытия...";
//    cin.ignore();
//    cin.get();
//}

int sortFromDirectory() {
    std::string path = "."; // укажите путь к каталогу
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            auto ext = entry.path().extension().string();
            if (!ext.empty()) {
                // Создаем папку по расширению, если не существует
                fs::path target_dir = entry.path().parent_path() / ext.substr(1);
                fs::create_directory(target_dir);
                // Перемещаем файл
                fs::path target_path = target_dir / entry.path().filename();
                fs::rename(entry.path(), target_path);
            }
        }
    }
    std::cout << "Files sorting to extensions." << std::endl;
    return 0;
}

void sortMyFiles() {

    int mode;
    cout << "Select sort mode:\n1 - Type fiels\n2 - Extensions files\n > [Default 1]: ";
    cin >> mode;
    if (cin.fail()) {
        mode = 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int copy;
    cout << "Copy or transfer file?:\n1 - Copy\n2 - Move\n > [Default 1]: ";
    cin >> copy;
    if (cin.fail()) {
        copy = 1;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string dir = "C:/Users/ilya/Desktop/sorter/";
 
    for (const auto& file : fs::recursive_directory_iterator(PATH)) {
        if (fs::is_regular_file(file)) {
            string extension = file.path().extension().string().substr(1); // Remove the dot
            string target_dir;

            if (mode == 2) {
                target_dir = dir + "." + extension;
            }
            else {
                if (find(images.begin(), images.end(), extension) != images.end()) {
                    target_dir = dir + "images";
                }
                else if (find(audio.begin(), audio.end(), extension) != audio.end()) {
                    target_dir = dir + "audio";
                }
                else if (find(videos.begin(), videos.end(), extension) != videos.end()) {
                    target_dir = dir + "videos";
                }
                else if (find(documents.begin(), documents.end(), extension) != documents.end()) {
                    target_dir = dir + "documents";
                }
                else if (find(archives.begin(), archives.end(), extension) != archives.end()) {
                    target_dir = dir + "archives";
                }
                else if (find(programs.begin(), programs.end(), extension) != programs.end()) {
                    target_dir = dir + "programs";
                }
                else if (find(scripts.begin(), scripts.end(), extension) != scripts.end()) {
                    target_dir = dir + "scripts";
                }
                else if (find(torrents.begin(), torrents.end(), extension) != torrents.end()) {
                    target_dir = dir + "torrents";
                }
                else if (find(design.begin(), design.end(), extension) != design.end()) {
                    target_dir = dir + "design";
                }
                else if (find(database.begin(), database.end(), extension) != database.end()) {
                    target_dir = dir + "database";
                }
                else if (find(models.begin(), models.end(), extension) != models.end()) {
                    target_dir = dir + "models";
                }
                else {
                    target_dir = dir + "other";
                }
            }

            fs::create_directories(target_dir);
            if (copy == 2) {
                fs::rename(file.path(), target_dir + "/" + file.path().filename().string());
            }
            else {
                fs::copy(file.path(), target_dir + "/" + file.path().filename().string(), fs::copy_options::overwrite_existing);
            }
        }
    }

    cout << "Sort process secesfully. Enter to close ...";
    cin.ignore();
    cin.get();
}
int main() {
    sortMyFiles();
    return 0;
}