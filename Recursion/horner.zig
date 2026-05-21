const std = @import("std");

fn power(i: f64, n: f64) f64 {
    if (n <= 0) {
        return 1;
    }

    if (@mod(n, 2) == 0) {
        return power(i * i, @divFloor(n, 2));
    } else {
        return i * power(i * i, @divFloor((n - 1), 2));
    }
}

fn factorial(i: f64) f64 {
    if (i > 0) {
        return i * factorial(i - 1);
    } else {
        return 1;
    }
}

// for e^x
// use incrementing counter instead of global/static
fn horner(i: f64, n: f64, c: f64) f64 {
    if (c - n == 0) {
        return 1;
    }
    return 1 + (i / c * horner(i, n, c + 1));
}

pub fn main(init: std.process.Init) void {
    _ = init;
    const t = horner(1, 10, 1);
    std.debug.print("{}", .{t});

    return;
}
