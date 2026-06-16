use std::iter;

impl Solution {
    pub fn process_str(s: String) -> String {
        let mut ret = String::new();
        
        for c in s.chars() {
            if c == '*' { let _ = ret.pop(); }
            else if c == '#' {
                let copy = ret.clone();
                ret.push_str(&copy);
            }
            else if c == '%' {
                ret = ret
                    .chars()
                    .rev()
                    .collect();
            }
            else { 
                println!("{c}");
                ret.push(c);
             }
        }

        ret
    }
}