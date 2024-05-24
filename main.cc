#include <drogon/HttpAppFramework.h>

using namespace drogon;

using Callback = std::function<void(const HttpResponsePtr&)>;

int main() {
    app().addListener("127.0.0.1", 8080);
    app().registerHandler("/", [](const HttpRequestPtr& req, Callback&& callback)
        {
            auto resp = HttpResponse::newHttpResponse();
            resp->setContentTypeCode(ContentType::CT_TEXT_HTML);
            resp->setBody("<h1>Simple Drogon App With Tamplate</h1>");
            callback(resp);
    });

    app().run();
    return 0;
}