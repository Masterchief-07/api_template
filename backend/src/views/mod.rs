pub mod hello;
pub mod example;

use actix_web::Responder;

use crate::schemas::response::response;

pub async fn not_found_default() -> impl Responder{
    return response(
        404,
        "not found".into(),
    )
}