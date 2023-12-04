mod services;
mod views;
use salvo::prelude::*;
use views::hello::hello_views;

// #[handler]
// async fn hello() -> &'static str{
//     "hello world"
// }

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt().init();
    let router = Router::new()
                        .push(hello_views());
    let acceptor = TcpListener::new("127.0.0.1:8001").bind().await;
    Server::new(acceptor).serve(router).await;
}