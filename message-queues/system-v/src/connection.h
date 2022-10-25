#define SERVER_KEY_PATHNAME "/tmp/mqueue_server_key"
#define PROJECT_ID 'M'
#define QUEUE_PERMISSIONS 0660

struct message_text {
    int qid;
    char buf [200];
};

struct message {
    long message_type;
    struct message_text message_text;
};
