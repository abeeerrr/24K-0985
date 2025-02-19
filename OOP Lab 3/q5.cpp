#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[100]; 
    int songCount;
    string currentlyPlayingSong;

public:
    MusicPlayer() {
        songCount = 0;
        currentlyPlayingSong = "";
    }

    void addSong(string song) {
        if (songCount < 100) {
            playlist[songCount] = song;
            songCount++;
            cout << "'" << song << "' has been added to the playlist.\n";
        } else {
            cout << "Playlist is full!\n";
        }
    }

    void removeSong(string song) {
        bool found = false;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                found = true;
                for (int j = i; j < songCount - 1; j++) {
                    playlist[j] = playlist[j + 1];
                }
                songCount--;
                cout << "'" << song << "' has been removed from the playlist.\n";
                if (currentlyPlayingSong == song) {
                    currentlyPlayingSong = "";
                }
                break;
            }
        }
        if (!found) {
            cout << "'" << song << "' is not in the playlist.\n";
        }
    }

    void playSong(string song) {
        bool found = false;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                currentlyPlayingSong = song;
                cout << "Now playing: " << song << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "'" << song << "' is not in the playlist. Add it first!\n";
        }
    }

    void displayPlaylist() {
        if (songCount == 0) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Playlist:\n";
        for (int i = 0; i < songCount; i++) {
            cout << i + 1 << ". " << playlist[i] << "\n";
        }
    }

    void showCurrentSong() {
        if (currentlyPlayingSong.empty()) {
            cout << "No song is currently playing.\n";
        } else {
            cout << "Currently playing: " << currentlyPlayingSong << "\n";
        }
    }
};

int main() {
    MusicPlayer player;
 
    player.addSong("MATZ");
    player.addSong("Playground");
    player.addSong("Save Me");


    player.displayPlaylist();

    player.playSong("Playground");
    player.showCurrentSong();

    player.removeSong("MATZ");
    player.displayPlaylist();

    player.playSong("MATZ");

    return 0;
}

