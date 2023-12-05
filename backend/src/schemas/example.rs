use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize)]
pub struct Example{
    pub name: String
}