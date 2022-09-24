mod path;
fn main() {
    let mgr = path::pathmgr::new(String::from("/root"));
    for path in mgr.unwrap().get_sub_files().unwrap() {
        println!("{}", path.to_str().unwrap());
    }
}
