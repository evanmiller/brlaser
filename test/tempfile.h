// This file is part of the brlaser printer driver.
//
// Copyright 2014 Peter De Wachter
//
// brlaser is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// brlaser is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with brlaser.  If not, see <http://www.gnu.org/licenses/>.

#ifndef TEMPFILE_H
#define TEMPFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <vector>
#include "config.h"

class tempfile {
 public:
  explicit tempfile()
        file_(tmpfile()) {
  }

  ~tempfile() {
    fclose(file_);
  }

  FILE *file() {
    return file_;
  }

  std::vector<uint8_t> data() {
    if (fflush(file_))
      return std::vector<uint8_t>();
    size_t temp_size = ftell(file_);
    void *temp = mmap(NULL, temp_size, PROT_READ, 0, fileno(file_), 0);
    std::vector<uint8_t> result = std::vector<uint8_t>((char *)temp, (char *)temp + temp_size);
    munmap(temp, temp_size);
    return result;
  }

 private:
  FILE *file_;
};

#endif  // TEMPFILE_H
