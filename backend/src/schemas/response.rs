use actix_web::{
    body::BoxBody, http::header::ContentType, HttpRequest, HttpResponse, Responder, http::StatusCode 
};
use serde::Serialize;
use serde_json;

#[derive(Serialize)]
pub struct Response<T:Serialize>{
    status: i32,
    message: String,
    data: Option<T>
}

pub fn response(status:i32, message:String) -> Response<()>{
    Response { status: status, message: message, data: Some(()) }
}

pub fn response_data<T:Serialize>(status:i32, message:String, data:Option<T>) -> Response<T>{
    Response { status: status, message: message, data: data }
}

impl<T:Serialize> Responder for Response<T>{
    type Body = BoxBody;

    fn respond_to(self, _req: &HttpRequest) -> HttpResponse<Self::Body>{
        let body = serde_json::to_string(&self).unwrap();

        HttpResponse::Ok()
        .status(StatusCode::from_u16(self.status as u16).unwrap())
        .content_type(ContentType::json())
        .body(body)
    }
}