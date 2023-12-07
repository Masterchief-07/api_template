use serde::{Serialize, Deserialize};
use sea_orm::entity::prelude::*;
use sea_orm::EntityTrait;
// use chrono::prelude::*;

#[derive(Clone, Debug, PartialEq, Eq, DeriveEntityModel, Deserialize, Serialize)]
#[sea_orm(table_name = "examples")]
pub struct Model{
    #[sea_orm(primary_key, auto_increment=true)]
    #[serde(skip_deserializing)]
    pub id:i32,
    pub name:String,
    // pub created_at: DateTime,
    // pub updated_at: DateTime
}

#[derive(Copy, Clone, Debug, EnumIter, DeriveRelation)]
pub enum Relation{}

impl ActiveModelBehavior for ActiveModel{}