mod database;
mod schemas;
mod services;
mod views;
use actix_web::{HttpServer, App};
use crate::views::hello::hello_views;

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
        .configure(hello_views)
    })
    .bind(("127.0.0.1", 8001))?
    .run()
    .await
}
// use actix_web::{web, App, HttpServer, Responder};

// async fn index() -> impl Responder {
//     "Hello world!"
// }

// #[actix_web::main]
// async fn main() -> std::io::Result<()> {
//     HttpServer::new(|| {
//         App::new().service(
//             // prefixes all resources and routes attached to it...
//             web::scope("/app")
//                 // ...so this handles requests for `GET /app/index.html`
//                 .route("/index.html", web::get().to(index)),
//         )
//     })
//     .bind(("127.0.0.1", 8080))?
//     .run()
//     .await
// }