use actix_web::{
    body::BoxBody, http::header::ContentType, HttpRequest, HttpResponse, Responder
};
use serde::Serialize;
use serde_json;

#[derive(Serialize)]
pub struct Response{
    pub status: i32,
    pub message: String,
}

impl Responder for Response{
    type Body = BoxBody;

    fn respond_to(self, _req: &HttpRequest) -> HttpResponse<Self::Body>{
        let body = serde_json::to_string(&self).unwrap();

        HttpResponse::Ok()
        .content_type(ContentType::json())
        .body(body)
    }
}
#[derive(Serialize)]
pub struct ResponseData<T:Serialize>{
    pub status: i32,
    pub message: String,
    pub data: T
}

impl<T:Serialize> Responder for ResponseData<T>{
    type Body = BoxBody;

    fn respond_to(self, _req: &HttpRequest) -> HttpResponse<Self::Body>{
        let body = serde_json::to_string(&self).unwrap();

        HttpResponse::Ok()
        .content_type(ContentType::json())
        .body(body)
    }
}