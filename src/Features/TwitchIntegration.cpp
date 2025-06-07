#include "Event.hpp"
#include "Modules/Client.hpp"
#include "Utils/TwitchConnection.hpp"
#include "Variable.hpp"

Variable p2sm_twitch_chat_enabled("p2sm_twitch_chat_enabled", "0", "Enables Twitch chat integration.\n");
Variable p2sm_twitch_chat_channel("p2sm_twitch_chat_channel", "", "The Twitch channel to connect to.\n");
Variable p2sm_twitch_chat_color("p2sm_twitch_chat_color", "255 255 255", "The color of the Twitch chat messages.\n");

TwitchConnection twitchConnection;

ON_EVENT(PRE_TICK) {
    if (!p2sm_twitch_chat_enabled.GetBool() || strlen(p2sm_twitch_chat_channel.GetString()) == 0) {
        if (twitchConnection.IsConnected()) {
            twitchConnection.Disconnect();
        }
        return;
    }
    std::string channel = p2sm_twitch_chat_channel.GetString();
    if (twitchConnection.GetChannel().compare(channel) != 0) {
        twitchConnection.JoinChannel(channel);
    }
    if (!twitchConnection.IsConnected()) {
        twitchConnection.JoinChannel(channel);
    }
    auto twitchMsgs = twitchConnection.FetchNewMessages();
    for (auto msg : twitchMsgs) {
        std::string message = msg.username + ": " + msg.message;
        Color color = Utils::GetColor(p2sm_twitch_chat_color.GetString()).value_or(Color(255, 255, 255));
        client->Chat(color, message.c_str());
    }
}

ON_EVENT(P2SM_UNLOAD) {
    if (twitchConnection.IsConnected()) {
        twitchConnection.Disconnect();
    }
}
